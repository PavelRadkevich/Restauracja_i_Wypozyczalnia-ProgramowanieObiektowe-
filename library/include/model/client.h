//
// Created by student on 18.03.2022.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H
namespace wypozyczalnia {
    class client {
    private:
        std::string firstName;
        std::string lastName;
        std::string personalID;

    public:
        client(std::string initial_firstName, std::string initial_lastName, std::string initial_personalID);
        ~client();
        std::string getClientinfo ();

        //gettery
        std::string get_firstName ();
        std::string get_lastName ();
        std::string get_personalID ();

        //settery
        void set_firstName (std::string);
        void set_lastName (std::string);
        void set_personalID (std::string);
    };
}
#endif //CARRENTAL_CLIENT_H
