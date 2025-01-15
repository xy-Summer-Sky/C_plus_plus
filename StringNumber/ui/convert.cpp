//
// Created by Lenovo on 24-7-15.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Convert.h" resolved
#include "convert.h"
#include "ui_Convert.h"
#include<stack>
#include <QtCore>


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

//QString Convert::numberToTraditionalChinese(const QString& numStr) {
//    QStringList numMap;
//    numMap << QStringLiteral("零") << QStringLiteral("壹") << QStringLiteral("贰") << QStringLiteral("叁") << QStringLiteral("肆")
//           << QStringLiteral("伍") << QStringLiteral("陆") << QStringLiteral("柒") << QStringLiteral("捌") << QStringLiteral("玖");
//    QStringList units;
//    units << QStringLiteral("元") << QStringLiteral("拾") << QStringLiteral("佰") << QStringLiteral("仟") << QStringLiteral("")
//          << QStringLiteral("万") << QStringLiteral("亿");
//    QStringList smallUnits;
//    smallUnits << QStringLiteral("角") << QStringLiteral("分");
//
//    QString result;
//    bool ok;
//    long long yuan = numStr.section('.', 0, 0).toLongLong(&ok); // 整数部分
//    long long jiaoFen = (numStr.section('.', 1, 1).left(2) + "00").left(2).toLongLong(&ok); // 小数部分，四舍五入
//
//    // 处理整数部分
//    int unitIndex = 0;
//    while (yuan > 0)
//    {
//        int digit = yuan % 10;
//        if (digit > 0)
//        {
//            result = numMap[digit] + units[unitIndex % 4] + ((unitIndex % 4 == 0 && unitIndex > 0) ? units[4 + unitIndex / 4] : "") + result;
//        }
//        else if (!result.isEmpty() && result.front() != QStringLiteral("零"))
//        {
//            result = QStringLiteral("零") + result;
//        }
//        yuan /= 10;
//        ++unitIndex;
//    }
//
//    if (result.isEmpty()) result = QStringLiteral("零元"); // 处理0元的情况
//    else result += "";
//
//    // 处理小数部分
//    if (jiaoFen == 0) result += QStringLiteral("整");
//    else {
//        if (jiaoFen / 10 > 0) result += numMap[jiaoFen / 10] + smallUnits[0];
//        if (jiaoFen % 10 > 0) result += numMap[jiaoFen % 10] + smallUnits[1];
//    }
//
//    return result;
//}
QString Convert::numberToTraditionalChinese(const QString& moneySumOriginal) {

    QStringList zhCN;
    zhCN << QStringLiteral("零") << QStringLiteral("壹") << QStringLiteral("贰") << QStringLiteral("叁") << QStringLiteral("肆")
         << QStringLiteral("伍") << QStringLiteral("陆") << QStringLiteral("柒") << QStringLiteral("捌") << QStringLiteral("玖");
    //std::string zhCN[] = {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};

    //std::string zhUNIT[] = { "拾","佰","仟","万","拾","佰","仟","亿" ,"拾","佰","仟","万", "拾","佰","仟"};
    QStringList zhUNIT;
    zhUNIT << QStringLiteral("拾") << QStringLiteral("佰") << QStringLiteral("仟") << QStringLiteral("万") << QStringLiteral("拾")
           << QStringLiteral("佰") << QStringLiteral("仟") << QStringLiteral("亿") << QStringLiteral("拾") << QStringLiteral("佰")
           << QStringLiteral("仟") << QStringLiteral("万") << QStringLiteral("拾") << QStringLiteral("佰") << QStringLiteral("仟");
    QStringList parts = moneySumOriginal.split('.');
    char cc[32] = {0}; // 初始化数组，确保剩余部分为空
    char decimalArray[32] = {0}; // 用于保存小数部分的数组


// 检查是否存在整数部分
    if (!parts.empty()) {
        std::string integerPart = parts.at(0).toStdString();
        strncpy_s(cc, integerPart.c_str(), sizeof(cc) - 1);
        cc[sizeof(cc) - 1] = '\0'; // 确保字符串以空字符结尾
    }

// 检查是否存在小数部分
    if (parts.size() > 1) {
        std::string decimalPart = parts.at(1).toStdString();
        strncpy_s(decimalArray, decimalPart.c_str(), sizeof(decimalArray) - 1);
        decimalArray[sizeof(decimalArray) - 1] = '\0'; // 确保字符串以空字符结尾
    }




    std::string str_value(cc);
    std:: stack<int>nValue;
    for (int i = 0; i < str_value.length(); i++)
    {
        const char bb = str_value.at(i);
        nValue.push((bb - '0'));
    }
    std::stack<QString>cn;
    int ii = 0;
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
    std::stack<QString>cn2;
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
    std::stack<QString>cn3;
    QString newstr = "";
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
    if (newstr.length() > 0)newstr += QStringLiteral("元");
    // 检查是否存在小数部分，并进行四舍五入

    // Round the decimal part if it exists
    if (parts.size() > 1 && parts[1].length() > 2) {
        double decimalPart = parts[1].left(3).toDouble() / qPow(10, parts[1].left(3).length());
        QString roundedDecimal = QString::number(decimalPart, 'f', 2).split('.')[1];
        parts[1] = roundedDecimal;
    }
    if (parts.size() > 1) {
        std::string decimalPart = parts.at(1).toStdString();
        if (!decimalPart.empty()) {
            int firstDecimal = decimalPart[0] - '0';
            if (firstDecimal != 0) { // Ignore if the digit is 0
                newstr += zhCN[firstDecimal] + QStringLiteral("角");
            }
        }
        if (decimalPart.length() >= 2) {
            // Convert the second decimal place and append "分"
            int secondDecimal = decimalPart[1] - '0';
            if (secondDecimal != 0) { // Ignore if the digit is 0
                newstr += zhCN[secondDecimal] + QStringLiteral("分");
            }
        }
    }
    else {
        newstr += QStringLiteral("整");
    }

// Note: The rest of the function remains unchanged.

//        bool ok;
//        long long jiaoFen = (moneySumOriginal.section('.', 1, 1).left(2) + "00").left(2).toLongLong(&ok);
    return newstr;

}