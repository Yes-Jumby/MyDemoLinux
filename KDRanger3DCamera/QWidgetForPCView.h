#ifndef QWIDGETFORPCVIEW_H
#define QWIDGETFORPCVIEW_H
#include <QWidget>
#include <QWebEngineView>
#include <QUrl>
#include <memory>
class QWidgetForPCView : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetForPCView(QWidget *parent = nullptr);
    //~QWidgetForPCView();
    void setDisplayWeb(const QUrl &url);
    void runJavaScript(const QString &script);
protected:
    void resizeEvent(QResizeEvent *);
signals:
    void loadFinished(bool ok);
private slots:
    void on_loadFinished(bool ok);
private:
    std::shared_ptr<QWebEngineView> m_webView ;
};

#endif // QWIDGETFORPCVIEW_H
