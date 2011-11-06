#include "headers.h"
#include "enums.h"
#include <caml/mlvalues.h>
#include <stdio.h>
#include <QtGui/QWidget>
#include "AA.h"

void QWidget_twin::call_super_keyPressEvent(QKeyEvent *ev) {
  foo(1);
  QWidget::keyPressEvent(ev);
}
void QWidget_twin::foo(int x) {
  if (x>0)
    foo(x-1);
  else 
    return;
}
void QWidget_twin::keyPressEvent(QKeyEvent *ev) {
    CAMLparam0();
    CAMLlocal2(meth,camlobj);
    GET_CAML_OBJECT(this,the_caml_object);
    camlobj = (value)the_caml_object;
    printf ("tag of camlobj is %d\n", Tag_val(camlobj));
    printf ("inside QWidget_twin::keyPressedEvent, camlobj = %x\n", camlobj);
    meth = caml_get_public_method( camlobj, caml_hash_variant("keyPressEvent"));
    if (meth==0)
      printf ("total fail\n");
    printf ("tag of meth is %d\n", Tag_val(meth) );
    printf("calling callback of meth = %x\n",meth);
    caml_callback2(meth, camlobj, (value)ev);
    printf ("exit from QWidget_twin::keyPressedEvent\n");
    CAMLreturn0;
}

extern "C" {

value create_QWidget_twin(value arg0) {
  CAMLparam1(arg0);
  QWidget* _arg0 = (arg0==Val_none) ? NULL : ((QWidget* )(Some_val(arg0)));
  QWidget_twin *_ans = new QWidget_twin(_arg0);
  CAMLreturn((value)_ans);
}

value qWidget_twin_super_keyPressEvent(value self,value arg0) {
  CAMLparam2(self,arg0);
  printf("inside qWidget_twin_super_keyPressEvent\n");
  //QWidget_twin *_self = (QWidget_twin*)self;
  QWidget_twin *_self = qobject_cast<QWidget_twin*>((QObject*)self);
  QKeyEvent* _arg0 = (QKeyEvent* ) (arg0);
  printf ("keyEvent parameter = %d\n", _arg0);
  _self -> call_super_keyPressEvent(_arg0);
  CAMLreturn(Val_unit);
}

value qWidget_twin_show(value self) {
  CAMLparam1(self);
  QWidget_twin *_self = qobject_cast<QWidget_twin*>((QObject*)self);
  //QWidget_twin *_self = (QWidget_twin*)self;
  _self -> show();
  CAMLreturn(Val_unit);
}

}
