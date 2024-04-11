# Use an official Ubuntu as a parent image
FROM ubuntu:latest

# Set the working directory inside the container
WORKDIR /app

# Update and install necessary packages
RUN apt-get update && \
    apt-get install -y flex g++ make && \
    rm -rf /var/lib/apt/lists/*

# Copy the Makefile and lex file into the container
COPY Makefile .
COPY analisadorLexico.l .

# Build the lex file to C
RUN lex analisadorLexico.l

# Compile the program using the Makefile
RUN make all

# Run the compiled program
CMD ["./saida", "<", "entrada.txt"]

# Clean up unnecessary files after running the program
RUN make clean
