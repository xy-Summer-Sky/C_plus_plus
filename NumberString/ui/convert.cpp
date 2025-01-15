//
// Created by Lenovo on 24-7-15.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Convert.h" resolved

#include "convert.h"
#include "ui_Convert.h"
#include<stack>



Convert::Convert(QWidget *parent) :
        QWidget(parent), ui(new Ui::Convert) {
    ui->setupUi(this);

}

Convert::~Convert() {
    delete ui;
}

void Convert::convertAndDisplay() {
    QString beforeText = ui->labelBefore->text();
    QString afterText = ui->labelAfter->text();
    QString numberText = ui->lineEditNumber->text();

    QString convertedNumber = numberToTraditionalChinese(numberText);
    QString result = beforeText + convertedNumber + afterText;

    ui->outputLineEdit->setText(result);
}

QString Convert::numberToTraditionalChinese(const QString& numStr) {
    QString newstr2 = "NA";
    std::string zhCN[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};

    std::string zhUNIT[] = {"拾", "佰", "仟", "万", "拾", "佰", "仟", "亿", "拾", "佰", "仟", "万", "拾", "佰", "仟"};


        std::string tempStr = numStr.toStdString();
        const char *tempCStr = tempStr.c_str();

        char cc[32];

        strncpy(cc, tempCStr, sizeof(cc) - 1);

        cc[sizeof(cc) - 1] = '\0';
        scanf("%s", cc);
        std::string str_value(cc);

        std::stack<int> nValue;
        for (int i = 0; i < str_value.length(); i++) {
            const char cc = str_value.at(i);
            nValue.push((cc - '0'));
        }
        std::stack<std::string> cn;
        int ii = 0;
        int zcount = 0;
        while (!nValue.empty()) {
            int value = nValue.top();
            cn.push(zhCN[value]);
            cn.push(zhUNIT[ii]);
            nValue.pop();
            ii++;
        }
        if (!cn.empty()) {
            cn.pop();
        }
        //删除零
        std::stack<std::string> cn2;
        while (!cn.empty()) {
            while (cn.top() != zhCN[0]) {
                cn2.push(cn.top());
                cn.pop();
                if (cn.empty()) {
                    break;
                }
            }
            if (cn.empty()) {
                break;
            }
            //找到零结束
            while (cn.top() == zhCN[0]) {

                cn.pop();
                if (cn.empty()) {
                    break;
                }
                if (cn.top() == zhUNIT[3])//保留万
                {
                    cn2.push(zhUNIT[3]);
                }
                if (cn.top() == zhUNIT[7])//保留亿
                {
                    cn2.push(zhUNIT[7]);
                }
                cn.pop();
            }//找到零结束
            if (!cn.empty()) {
                cn2.push(zhCN[0]);
            }

        }
        std::stack<std::string> cn3;
        std::string newstr = "";
        while (!cn2.empty()) {
            cn3.push(cn2.top());
            cn2.pop();
        }
        while (!cn3.empty()) {
            newstr += cn3.top();
            cn3.pop();
        }
        newstr2 = QString::fromStdString(newstr);
//            cout << "newstr is " << newstr.c_str() << endl;


    return newstr2;

}

