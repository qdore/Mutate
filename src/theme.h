#ifndef THEME_H
#define THEME_H

#include <QSize>
#include <QString>
#include <QColor>

class Theme
{
public:
    Theme() {}
    Theme(QSize dimensions, QString groupBoxStylesheet, QString plainTextEditStylesheet, QString listWidgetStylesheet,\
          int fontSize, qreal blurRadius, QColor shadowColor, qreal shadowOffset);
    ~Theme();

    QSize dimensions() const;
    void setDimensions(const QSize &dimensions);

    QString groupBoxStylesheet() const;
    void setGroupBoxStylesheet(const QString &groupBoxStylesheet);

    QString plainTextEditStylesheet() const;
    void setPlainTextEditStylesheet(const QString &plainTextEditStylesheet);

    QString listWidgetStylesheet() const;
    void setListWidgetStylesheet(const QString &listWidgetStylesheet);

    qreal blurRadius() const;
    void setBlurRadius(const qreal &blurRadius);

    QColor shadowColor() const;
    void setShadowColor(const QColor &shadowColor);

    qreal shadowOffset() const;
    void setShadowOffset(const qreal &shadowOffset);

    int fontSize() const;
    void setFontSize(int value);

    int beginHeight() const;
    void setBeginHeight(int beginHeight);

    int listWidgetY() const;
    void setListWidgetY(int listWidgetY);

private:
    int mBeginHeight;
    int mListWidgetY;
    QSize mDimensions;
    QString mGroupBoxStylesheet;
    QString mPlainTextEditStylesheet;
    QString mListWidgetStylesheet;
    int mFontSize;
    qreal mBlurRadius;
    QColor mShadowColor;
    qreal mShadowOffset;
};

#endif // THEME_H
