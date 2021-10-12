/*
** EPITECH PROJECT, 2019
** server
** File description:
** TcpServer
*/

#include "TcpServer.hpp"

std::string make_daytime_string()
{
    using namespace std;
    time_t now = time(0);
    return ctime(&now);
}

tcp_connection::tcp_connection(boost::asio::io_service& io_service) : socket_(io_service) {

}

void tcp_connection::download(void) {
    std::string line;
    std::ifstream myfile ("./text.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            boost::asio::async_write(socket_, boost::asio::buffer(line + "\n"),
            boost::bind(&tcp_connection::handle_write, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
            sleep(1);
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}

static void *init(void *args)
{
    tcp_connection **tcp = static_cast<tcp_connection **>(args);
    (*tcp)->download();
    pthread_exit(NULL);
    return (NULL);
}

tcp_server::tcp_server(boost::asio::io_service& io_service) : acceptor_(io_service, tcp::endpoint(tcp::v4(), 3031)) {
    start_accept();
}

void tcp_server::start_accept() {
    tcp_connection *co = new tcp_connection(acceptor_.get_io_service());

    acceptor_.async_accept(co->socket(),
        boost::bind(&tcp_server::handle_accept, this, co,
        boost::asio::placeholders::error));
}

void tcp_server::handle_accept(tcp_connection *new_connection, const boost::system::error_code& error) {
    if (!error) {
        pthread_t t;
        pthread_create(&t, NULL, &init, (void *)&new_connection);
        start_accept();
    }
}

int main()
{
    try
    {
        boost::asio::io_service io_service;
        tcp_server server(io_service);
        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}