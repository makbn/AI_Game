
#include <iostream>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;


/**
 * @brief socket programming interface in cpp
 * @based on a sample code from geeksforgeeks.com
 */
class Socket
{
  private: 
    struct sockaddr_in address;
    int sock = 0;
    struct sockaddr_in serv_addr;

    char buffer[1024] = {0};

    char *host;
    int port;
public:
/**
 * @brief class constructor
 * @param h : host address in string
 * @param p : port in int
 */
    Socket(char *h, int p)
    {
        this->host = h;
        this->port = p;
        this->socketConnect();
    }
/**
 * @brief connect to host through port
 * 
 * @return bool true if everything's ok
 */
    bool socketConnect()
    {
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            cout << "\n Socket creation error \n"
                 << endl;
            return false;
        }

        memset(&serv_addr, '0', sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);

        if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0)
        {
            cout << "\nInvalid address \n";
            return false;
        }

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            cout << "\nConnection Failed \n"
                 << endl;
            return false;
        }
        return true;
    }
    /**
 * @brief send string through socket
 * @param str : str to send
 * @return void
 */
    void socketSend(char *str)
    {
        send(sock, str, strlen(str), 0);
    }
/**
 * @brief recieve from socket
 * @param null
 * @return string of received data
 */
    char *socketReceive()
    {
        read(sock, buffer, 1024);
        return buffer;
    }
    
};
//sample
// int main()
// {

//     Socket s("127.0.0.1", 8080);
//     s.socketReceive();
//     s.socketSend("29");

//     return 0;
// }