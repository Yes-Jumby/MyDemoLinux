#include "QWidgetForPCView.h"
#include <QDebug>

QWidgetForPCView::QWidgetForPCView(QWidget *parent) : QWidget(parent),
    m_webView(nullptr)
{
    m_webView = std::make_shared<QWebEngineView>(this);

    connect(m_webView.get(),SIGNAL(loadFinished(bool)),this,SLOT(on_loadFinished(bool)));
    //m_webView->show();
}
//QWidgetForPCView::~QWidgetForPCView()
//{
//    if(m_webView != nullptr)
//    {
//        m_webView->deleteLater();
//    }
//}
void QWidgetForPCView::setDisplayWeb(const QUrl &url)
{
    qDebug()<<"setDisplayWeb";
    if(m_webView != nullptr)
    {
        //m_webView->setFocus();
        m_webView->load(url);
        //m_webView->show();
    }
}
void QWidgetForPCView::runJavaScript(const QString &script)
{
    qDebug()<<"runJavaScript";
    if(m_webView != nullptr)
    {
        m_webView->page()->runJavaScript(script);
    }
}
void QWidgetForPCView::resizeEvent(QResizeEvent *)
{
    if(m_webView != nullptr)
    {
        m_webView->resize(this->size());
    }
}
void QWidgetForPCView::on_loadFinished(bool ok)
{
    if(m_webView != nullptr)
    {
         emit loadFinished(ok);
    }
}
