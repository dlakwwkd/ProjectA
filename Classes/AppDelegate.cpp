#include "AppDelegate.h"
#include "MainScene.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview)
    {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }
    glview->setDesignResolutionSize(640, 480, ResolutionPolicy::FIXED_HEIGHT);

    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);

    auto scene = MainScene::createScene();
    director->runWithScene(scene);
    return true;
}

void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
