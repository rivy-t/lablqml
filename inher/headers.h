#pragma once
#include <QtCore/QObject>

#include "ml_headers.h"
#define Some_val(v) Field(v,0)

#define CAMLOBJ_PROPERTY "_camlobj"
#define GET_CAML_OBJECT(cppobj,varname) \
QVariant camlobj_variant = cppobj->property(CAMLOBJ_PROPERTY);\
 qlonglong varname = (camlobj_variant.isValid()) ? camlobj_variant.toLongLong() : 0;

value camlObj(QObject*);


#define Val_QWidget(v)            (*((QWidget **)        &Field(v, 0)))
#define Val_QObject(v)            (*((QObject **)        &Field(v, 0)))
#define Val_QWidget_twin(v)       (*((QWidget_twin **)   &Field(v, 0)))
#define Val_QKeyEvent(v)          (*((QKeyEvent **)      &Field(v, 0)))

#define QWidget_val(v)            (*((QWidget **)        Data_custom_val(v)))
#define QObject_val(v)            (*((QObject **)        Data_custom_val(v)))
#define QWidget_twin_val(v)       (*((QWidget_twin **)   Data_custom_val(v)))
#define QKeyEvent_val(v)          (*((QKeyEvent **)      Data_custom_val(v)))

