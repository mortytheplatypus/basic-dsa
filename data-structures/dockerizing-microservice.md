#### Question 1
I need some info regarding an app I built using microservice. 

I have one service named `my-service` running on port 8082. My service discovery runs on 8010 and my gateway runs on 8080. I have an endpoint in `my-service` named `/create` that performs a certain task. I am using Netflix Eureka and Spring Cloud. 

Now imagine all of them are running and I test my api. When I hit `http://localhost:8082/create`, it performs my task without an issue. When I hit `http://localhost:8080/my-service/create`, it gets routed to `my-service`, and the task gets performed like it is supposed to. 

Now I want to dockerize the whole system. Can you, step-by-step, show me the whole process? First show the individual Dockerfiles (You can assume all other variables needed), then show the docker-compose and then after running the docker-compose how do I access it?

#### Answer 1

**1. First, let's create individual Dockerfiles for each service.**
  - Service Discovery (Eureka Server):
```Dockerfile
FROM openjdk:17-jdk-slim
WORKDIR /app
COPY target/*.jar app.jar
EXPOSE 8010
ENTRYPOINT ["java", "-jar", "app.jar"]
```

  - API Gateway
```Dockerfile
FROM openjdk:17-jdk-slim
WORKDIR /app
COPY target/*.jar app.jar
EXPOSE 8080
ENTRYPOINT ["java", "-jar", "app.jar"]
```

  - My Service
```Dockerfile
FROM openjdk:17-jdk-slim
WORKDIR /app
COPY target/*.jar app.jar
EXPOSE 8082
ENTRYPOINT ["java", "-jar", "app.jar"]
```

**2. Now, let's create a `docker-compose.yml` file.**
```yaml
version: '3.8'

services:
  service-discovery:
    build: 
      context: ./service-discovery
      dockerfile: Dockerfile
    ports:
      - "8010:8010"
    networks:
      - microservice-network
    container_name: service-discovery

  api-gateway:
    build: 
      context: ./api-gateway
      dockerfile: Dockerfile
    ports:
      - "8080:8080"
    environment:
      - EUREKA_CLIENT_SERVICEURL_DEFAULTZONE=http://service-discovery:8010/eureka/
    depends_on:
      - service-discovery
    networks:
      - microservice-network
    container_name: api-gateway

  my-service:
    build: 
      context: ./my-service
      dockerfile: Dockerfile
    ports:
      - "8082:8082"
    environment:
      - EUREKA_CLIENT_SERVICEURL_DEFAULTZONE=http://service-discovery:8010/eureka/
    depends_on:
      - service-discovery
    networks:
      - microservice-network
    container_name: my-service

networks:
  microservice-network:
    driver: bridge
```

**3. Now, let's run the docker-compose.**
```bash
mvn clean install
docker-compose up --build
```

**4. Accessing the services:**
  - Service Discovery: `http://localhost:8010`
  - API Gateway: `http://localhost:8080/my-service/create`
  - My Service: `http://localhost:8082/create`
  
This should dockerize your microservices and make them accessible as per your requirements.

**IMPORTANT NOTES:**
Make sure your application.properties/application.yml files in each service are configured to use the correct URLs for service discovery. For example:
```yaml
eureka:
  client:
    serviceUrl:
      defaultZone: http://service-discovery:8010/eureka/
```

___

#### Question 2
Thanks. I got it. But I'd like to add some notes. Before dockerizing, I had the `eureka.client.serviceUrl.defaultZone` property to be `http://localhost:8010/eureka/`

Why did you change it? How is it configured? 

#### Answer 2
Ah, great question! This is a key concept when working with Docker containers.

When you run services locally (without Docker), using localhost works because all services are running on your machine, so `http://localhost:8010/eureka/` correctly points to your Eureka server.

However, in Docker, each container runs in its own isolated environment with its own networking namespace. When you use localhost inside a container, it refers to the container itself, not your host machine or other containers.

Here's a visualization:
```plaintext
Local Environment (Without Docker):

Service A (localhost:8082) ─────┐
                               ├──> Eureka (localhost:8010)
Service B (localhost:8083) ─────┘
```

```plaintext
Docker Environment:
Container A (my-service)    ─────┐
                                ├──> Container C (service-discovery)
Container B (api-gateway)   ─────┘

Each container has its own localhost!
```

In the Docker environment:
- When you use localhost inside the my-service container, it refers to that container only
- When you use localhost inside the service-discovery container, it refers to that container only
- That's why we:
  - Create a Docker network (microservice-network in the docker-compose.yml)
  - Connect all containers to this network
  - Use the container/service names as hostnames

So when we set:
```yaml
eureka:
  client:
    serviceUrl:
      defaultZone: http://service-discovery:8010/eureka/
```

**`service-discovery` refers to the container name of the Eureka server within the Docker network, i.e., whatever name you put in the `docker-compose.yml` file. Docker's internal DNS resolves this hostname to the correct container IP address.**

This is why it's important to:
 - Keep `localhost:8010` in your local development environment
 - Use `service-discovery:8010` in your Docker environment

You can handle this difference in several ways:
 - Use different application profiles (`dev` vs `docker`)
- Use environment variables
 - Override at runtime using Docker environment variables (as shown in the `docker-compose.yml`)

This way, your application can seamlessly switch between local and Docker environments without code changes.

#### Question 3
I have another followup question. Do I have to build individual images prior to running the docker-compose? 

#### Answer 3
No, you don't need to build individual images separately before running docker-compose! That's one of the conveniences of using docker-compose.
When you run:
```bash
docker-compose up --build
```
Docker Compose automatically builds the images for each service based on the Dockerfiles provided in the `docker-compose.yml` file. It then starts the containers based on these images.

Docker Compose will:
- Read your docker-compose.yml file
- Build all the images defined with a **build context**
- Create and start the containers

The `--build` flag specifically tells Docker Compose to rebuild the images even if they already exist.

Let's look at the relevant part of your docker-compose.yml:
```yaml
services:
  my-service:
    build: 
      context: ./my-service      # Points to directory containing Dockerfile
      dockerfile: Dockerfile     # Specifies which Dockerfile to use
    # ... other configurations ...
```