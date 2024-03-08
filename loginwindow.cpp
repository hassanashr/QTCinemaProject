#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "Users.h"
#include "register.h"
#include "welcomewindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->text_error->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_register_button_clicked()
{
    hide();
    Register* registerWindow = new Register(this);
    registerWindow->show();
}

void LoginWindow::on_login_button_clicked()
{
    QString username = ui->edit_username->text();
    QString password = ui->edit_password->text();
    int userIndex = findUserIndex(username);
    if(userIndex == -1) {
        ui->text_error->setVisible(true);
        return;
    }
    if(password == passwords[userIndex]) {
        hide();
        WelcomeWindow* welcomeWindow = new WelcomeWindow(this);
        welcomeWindow->show();
        welcomeWindow->setWelcomeMessage(userIndex);
    } else {
        ui->text_error->setVisible(true);
        return;
    }
}

