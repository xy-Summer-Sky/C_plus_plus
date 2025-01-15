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

    connect(ui->pushButton, &QPushButton::clicked, this, &Convert::convertAndDisplay);
}

Convert::~Convert() {
    delete ui;
}

void Convert::convertAndDisplay() {
    QString beforeText = ui->lineEdit->text();
    QString afterText = ui->lineEdit_2->text();
    QString numberText = ui->lineEditNumber->text();

    const int MAX_LENGTH = 15; // Define the maximum allowed length of the input number

    // Check if the input exceeds the maximum allowed length
    if (numberText.length() > MAX_LENGTH) {
        ui->outputLineEdit->setText("输入的数字过长，请输入较短的数字。");
        return; // Return early to avoid proceeding with the conversion
    }
    QString convertedNumber = numberToTraditionalChinese(numberText);
    QString result = beforeText + convertedNumber + afterText;

    ui->outputLineEdit->setText(result);
}

#include <map>
#include <vector>
#include <QString>

QString Convert::numberToTraditionalChinese(const QString& moneySumOriginal) {


    std::string zhCN[] = {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};

    std::string zhUNIT[] = { "拾","佰","仟","万","拾","佰","仟","亿" ,"拾","佰","仟","万", "拾","佰","仟"};

    QStringList parts = moneySumOriginal.split('.');
    char cc[32] = {0}; // 初始化数组，确保剩余部分为空
    char decimalArray[32] = {0}; // 用于保存小数部分的数组


// 检查是否存在整数部分
    if (!parts.empty()) {
        std::string integerPart = parts.at(0).toStdString();
        strncpy(cc, integerPart.c_str(), sizeof(cc) - 1);
        cc[sizeof(cc) - 1] = '\0'; // 确保字符串以空字符结尾
    }

// 检查是否存在小数部分
    if (parts.size() > 1) {
        std::string decimalPart = parts.at(1).toStdString();
        strncpy(decimalArray, decimalPart.c_str(), sizeof(decimalArray) - 1);
        decimalArray[sizeof(decimalArray) - 1] = '\0'; // 确保字符串以空字符结尾
    }




           std::string str_value(cc);
           std:: stack<int>nValue;
            for (int i = 0; i < str_value.length(); i++)
            {
                const char cc = str_value.at(i);
                nValue.push((cc - '0'));
            }
           std::stack<std::string>cn;
            int ii = 0;
            int zcount = 0;
            while (!nValue.empty())
            {
                int value = nValue.top();
                cn.push(zhCN[value]);
                cn.push(zhUNIT[ii]);
                nValue.pop();
                ii++;
            }
            if (!cn.empty())
            {
                cn.pop();
            }
            //删除零
            std::stack<std::string>cn2;
            while (!cn.empty())
            {
                while (cn.top() != zhCN[0])
                {
                    cn2.push(cn.top());
                    cn.pop();
                    if (cn.empty())
                    {
                        break;
                    }
                }
                if (cn.empty())
                {
                    break;
                }
                //找到零结束
                while (cn.top() == zhCN[0])
                {

                    cn.pop();
                    if (cn.empty())
                    {
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
                if (!cn.empty())
                {
                    cn2.push(zhCN[0]);
                }

            }
            std::stack<std::string>cn3;
            std::string newstr = "";
            while (!cn2.empty())
            {
                cn3.push(cn2.top());
                cn2.pop();
            }
            while (!cn3.empty())
            {
                newstr += cn3.top();
                cn3.pop();
            }

    //整数部分不为空则需要加上元
    if (newstr.length() > 0)
    newstr += "元";
    if (parts.size() > 1) {
        std::string decimalPart = parts.at(1).toStdString();
        if (decimalPart.length() >= 1) {
            // Convert the first decimal place and append "角"
            int firstDecimal = decimalPart[0] - '0';
            if (firstDecimal != 0) { // Ignore if the digit is 0
                newstr += zhCN[firstDecimal] + "角";
            }
        }
        if (decimalPart.length() >= 2) {
            // Convert the second decimal place and append "分"
            int secondDecimal = decimalPart[1] - '0';
            if (secondDecimal != 0) { // Ignore if the digit is 0
                newstr += zhCN[secondDecimal] + "分";
            }
        }
    }


// Note: The rest of the function remains unchanged.

//        bool ok;
//        long long jiaoFen = (moneySumOriginal.section('.', 1, 1).left(2) + "00").left(2).toLongLong(&ok);
        return QString::fromStdString(newstr);

}