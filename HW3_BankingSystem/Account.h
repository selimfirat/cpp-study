#ifndef ACCOUNT_H
#define ACCOUNT_H



class Account {
  public:
    Account( const int accountId, const double amount );
    Account(  );
    Account(Account &acc);
    ~Account();
    int getId();
    double getAmount();

  private:
    int id;
    double amount;

};

#endif
