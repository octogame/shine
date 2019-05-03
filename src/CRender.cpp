#include "kivy/CRender.hpp"

IRender* CreateIRender(IEngine* engine) {
  IRender* render = new CRender(engine);
  return render;
}


CRender::CRender(IEngine *engine) {

}

void CRender::init() {

}
void CRender::run() {

}
