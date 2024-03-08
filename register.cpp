#include "register.h"
#include "ui_register.h"
#include "Users.h"
#include "welcomewindow.h"

Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->username_err->setVisible(false);
    ui->password_err->setVisible(false);
    ui->age_err->setVisible(false);
    ui->all_fields_err->setVisible(false);
}

Register::~Register()
{
    delete ui;
}

void Register::on_register_button_clicked()
{
    // set all errors' visibility to false
    ui->username_err->setVisible(false);
    ui->password_err->setVisible(false);
    ui->age_err->setVisible(false);
    ui->all_fields_err->setVisible(false);
    bool isErr = false;

    // code to verify all fields are not empty
        // 1. check if line edits are empty
    bool isLineEditEmpty = (ui->register_userLineEdit->text().isEmpty() || ui->Register_passLineEdit->text().isEmpty()) ? true : false;
        // 2. check if the radio boxes are checked
    bool isGenderEmpty = (!ui->male_radio->isChecked() && !ui->female_radio->isChecked()) ? true : false;
    bool isAccTypeEmpty = (!ui->admin_radio->isChecked() && !ui->user_radio->isChecked()) ? true : false;
        // 3. check if none if the checkboxes are checked
    bool isGenreEmpty = true;
    QList<QCheckBox *> genreCheckBoxes = ui->genre_box->findChildren<QCheckBox *>();
    foreach(auto choice, genreCheckBoxes) {
        if(choice->isChecked()) {
            isGenreEmpty = false;
            break;
        }
    }

    if(isLineEditEmpty || isGenderEmpty || isAccTypeEmpty || isGenreEmpty) {
        isErr = true;
        ui->all_fields_err->setVisible(true);
    }

    // code to verify the age
    int userAge = 2024 - ui->year->currentText().toInt();
    if(userAge < 12) {
        isErr = true;
        ui->age_err->setVisible(true);
    }

    // code to verify the username and password

        QString username = ui->register_userLineEdit->text();
        QString password = ui->Register_passLineEdit->text();
        QString repassword = ui->Register_retypeLineEdit->text();
        int userIndex = findUserIndex(username);
        if(userIndex == -1) {

        }
        //checking if the username already exists
        if(username == usernames[userIndex]) {
            isErr = true;
            ui->username_err->setVisible(true);

        }
        //checking if password is identical
        if(!(repassword==password)) {
            isErr = true;
            ui->password_err->setVisible(true);
        }






    if(!isErr) {
        // code to add the new username, passowrd, and age & open the welcome window
            addNewUser(username);
            addNewPass(password);
            addAge(userAge);

            hide();
            WelcomeWindow* welcomeWindow = new WelcomeWindow(this);
            welcomeWindow->show();
            welcomeWindow->setWelcomeMessage(usersCount-1);

    }
}
