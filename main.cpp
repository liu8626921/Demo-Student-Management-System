#include "LoginDialog.h"
#include <QApplication>
#include <QIcon>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include<QTextCodec>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //设置app的图标
    a.setWindowIcon(QIcon("logo.ico"));
    //连接mysql数据库
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("school");
    if(db.open())
    {
    LoginDialog w;
    w.show();
    return a.exec();
    }
    else
    {
        QMessageBox::information(NULL,"提示","系统载入数据库失败，无法运行",QMessageBox::Yes);
    }
    return 0;
}
