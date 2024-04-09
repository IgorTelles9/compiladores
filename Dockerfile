# Use Ubuntu as base image
FROM ubuntu:latest

# Update package lists and install necessary tools
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    gcc-10 \
    g++-10 \
    cmake \
    && rm -rf /var/lib/apt/lists/*

# Set environment variables to use GCC 10
ENV CC=/usr/bin/gcc-10
ENV CXX=/usr/bin/g++-10

# Set working directory inside the container
WORKDIR /app

# Copy your C++ source code files into the container
COPY . .

# Compile your C++ program
RUN g++-10 -o myprogram identificador.cpp

# Set the command to run when the container starts
CMD ["./myprogram"]