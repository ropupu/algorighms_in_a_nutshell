# Get the GCC preinstalled image from Docker Hub
FROM gcc:4.9
 
# Specify the working directory
WORKDIR /usr/src/
 
CMD ["tail", "-f", "/dev/null"]
