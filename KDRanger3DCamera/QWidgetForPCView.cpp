#include "QWidgetForPCView.h"


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
    if(m_webView != nullptr)
    {
        //m_webView->load(url);
        //m_webView->setUrl(url);
        m_webView->setFocus();
        m_webView->setUrl(QUrl("http://127.0.0.1:8080/5_dat_cloud3D_potree_0.html"));
        m_webView->show();
    }
}
void QWidgetForPCView::runJavaScript(const QString &script)
{
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
