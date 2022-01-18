#include <jni.h>
#include <string>
#include <e3/Android/JniEnv.h>

static JavaVM* gJVM = NULL;
static e3::Keys* gKeys = nullptr;
static jobject gOnSetClipboardStringCallback = NULL;

extern "C" JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_initNative
(
    JNIEnv *env,
    jobject self,
    jint width,
    jint height
)
{
    e3::Android::JniEnv::Get()->SetEnv(env);

    if (gApp)
    {
        gApp->Resize(width, height);
        return;
    }

    e3::Size2i res(width, height);
    gApp = new Application("MDLite", e3::EE3OS::Android, e3::EE3Target::Mobile, res, res);

    if (!gJVM) env->GetJavaVM(&gJVM);
    gApp->SetOnCopyToClipboardCallback([env](const std::string& text) {
        //gJVM->AttachCurrentThread(const_cast<JNIEnv**>(&env), NULL);
        jclass cbClass = env->GetObjectClass(gOnSetClipboardStringCallback);
        jstring jMessage = e3::Android::JniEnv::Get()->StdStringToJString(text);
        jmethodID jonChangeCb = env->GetMethodID(cbClass, "setString", "(Ljava/lang/String;)V");
        env->CallVoidMethod(gOnSetClipboardStringCallback, jonChangeCb, jMessage);
        //  gJVM->DetachCurrentThread();
    });

    gApp->SetOnGetClipboardStringCallback([env]() {
        jclass cbClass = env->GetObjectClass(gOnSetClipboardStringCallback);
        jmethodID jonChangeCb = env->GetMethodID(cbClass, "getString", "()V");
        env->CallVoidMethod(gOnSetClipboardStringCallback, jonChangeCb);

        //gApp->SetClipboardStringInternal(text);
    });

    gKeys = new e3::Keys;
}

extern "C" JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_setClipboardStringNative
(
    JNIEnv *env,
    jobject /* this */,
    jstring jstr
)
{
    std::string text = e3::Android::JniEnv::Get()->JStringToStdString(jstr);
    gApp->SetClipboardString/*Internal*/(text);
}

extern "C" JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_resizeNative
(
    JNIEnv *env,
    jobject /* this */,
    jint width,
    jint height
)
{
    gApp->Resize(width, height);
}

extern "C" JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_renderNative
(
    JNIEnv *env,
    jobject /* this */
)
{
    gApp->Render();
}

extern "C" JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_onScrollNative
(
    JNIEnv *env,
    jobject /* this */,
    jfloat distanceX,
    jfloat distanceY,
    jfloat positionX,
    jfloat positionY
)
{
    if (!gApp)
        return;

    e3::Size2i res = gApp->GetResolution();

    float dX = (float) distanceX / res.Width;
    float dY = -(float) distanceY / res.Height;
    float posX = 2*positionX/ res.Width - 1.;
    float posY = -2*positionY / res.Height + 1.;
    posX = fmax(-1., fmin(1., posX));
    posY = fmax(-1., fmin(1., posY));
    e3::MouseEvent* pEvent = new e3::MouseEvent();
    pEvent->SetX(positionX);
    pEvent->SetY(positionY);
    pEvent->SetDistanceX(distanceX);
    pEvent->SetDistanceY(-distanceY);
    pEvent->SetType(e3::EEventType::MouseMove);
    gApp->OnScroll(pEvent);
}


extern "C" JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_onScaleNative
(
    JNIEnv *env,
    jobject /* this */,
    jfloat scaleFactor,
    jfloat positionX,
    jfloat positionY
)
{
    if (!gApp)
        return;

    e3::ScaleEvent* pEvent = new e3::ScaleEvent();
    pEvent->SetX(positionX);
    pEvent->SetY(positionY);
    pEvent->SetScaleFactor(scaleFactor);
    pEvent->SetType(e3::EEventType::Scale);
    gApp->OnScale(pEvent);
}

extern "C" JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_onDoubleTapNative
(
    JNIEnv *env,
    jobject /* this */,
    jfloat positionX,
    jfloat positionY
)
{
    if (!gApp)
        return;

    e3::MouseEvent* pEvent = new e3::MouseEvent();
    pEvent->SetX(positionX);
    pEvent->SetY(positionY);
    pEvent->SetType(e3::EEventType::DoubleClick);
    gApp->OnDoubleClick(pEvent);
}

extern "C" JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_onTouchDownNative
(
    JNIEnv *env,
    jobject instance,
    jfloat positionX,
    jfloat positionY
)
{
    e3::MouseEvent* pEvent = new e3::MouseEvent();
    pEvent->SetX(positionX);
    pEvent->SetY(positionY);
    pEvent->SetType(e3::EEventType::MouseDown);
    if (gApp) gApp->OnMouseDown(pEvent);
}

extern "C" JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_onTouchUpNative
(
    JNIEnv *env,
    jobject instance,
    jfloat positionX,
    jfloat positionY
)
{
    e3::MouseEvent* pEvent = new e3::MouseEvent();
    pEvent->SetX(positionX);
    pEvent->SetY(positionY);
    pEvent->SetType(e3::EEventType::MouseUp);
    if (gApp) gApp->OnMouseUp(pEvent);
}


extern "C" JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_onMoveNative
(
    JNIEnv *env,
    jobject instance,
    jfloat distanceX,
    jfloat distanceY
)
{

}

extern "C"
JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_onDestroyNative
(
    JNIEnv *env,
    jclass type
)
{
    if (gApp)
        gApp->OnDestroy();

    delete gApp;
    gApp = nullptr;

    delete gKeys;
    gKeys = nullptr;
}

static jobject gOnKeyboardStateChangeCallback = NULL;
extern "C"
JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_setOnKeyboardStateChangeCallbackNative
(
    JNIEnv *env,
    jclass type,
    jobject callback
)
{
    if (!gApp) return;

    if (!gJVM) env->GetJavaVM(&gJVM);
    gOnKeyboardStateChangeCallback = env->NewGlobalRef(callback);

    gApp->SetOnKeyboardStateChangeCallback([env](bool visible){
        gJVM->AttachCurrentThread(const_cast<JNIEnv**>(&env), NULL);
        jclass cbClass = env->GetObjectClass(gOnKeyboardStateChangeCallback);
        jmethodID jonChangeCb = env->GetMethodID(cbClass, "onChange", "(Z)V");
        env->CallVoidMethod(gOnKeyboardStateChangeCallback, jonChangeCb, static_cast<jboolean>(visible));
        //  gJVM->DetachCurrentThread();
    });
}

extern "C"
JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_setOnSetClipboardStringCallbackNative
(
    JNIEnv *env,
    jclass type,
    jobject callback
)
{
    if (!gApp) return;

    if (!gJVM) env->GetJavaVM(&gJVM);
    gOnSetClipboardStringCallback = env->NewGlobalRef(callback);

    /*gApp->SetOnKeyboardStateChangeCallback([env](bool visible){
        gJVM->AttachCurrentThread(const_cast<JNIEnv**>(&env), NULL);
        jclass cbClass = env->GetObjectClass(gOnKeyboardStateChangeCallback);
        jmethodID jonChangeCb = env->GetMethodID(cbClass, "onChange", "(Z)V");
        env->CallVoidMethod(gOnKeyboardStateChangeCallback, jonChangeCb, static_cast<jboolean>(visible));
        //  gJVM->DetachCurrentThread();
    });*/
}


static jobject gOnImageGalleryStateChangeCallback = NULL;
extern "C"
JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_setOnImageGalleryStateChangeCallbackNative
(
    JNIEnv *env,
    jclass type,
    jobject callback
)
{
    if (!gApp) return;

    if (!gJVM) env->GetJavaVM(&gJVM);
    gOnImageGalleryStateChangeCallback = env->NewGlobalRef(callback);

    gApp->SetOnImageGalleryStateChangeCallback([env](bool visible){
        gJVM->AttachCurrentThread(const_cast<JNIEnv**>(&env), NULL);
        jclass cbClass = env->GetObjectClass(gOnImageGalleryStateChangeCallback);
        jmethodID jonChangeCb = env->GetMethodID(cbClass, "onChange", "(Z)V");
        env->CallVoidMethod(gOnImageGalleryStateChangeCallback, jonChangeCb, static_cast<jboolean>(visible));
        //  gJVM->DetachCurrentThread();
    });
}

extern "C"
JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3Activity_onInteractionResultNative
(
    JNIEnv *env,
    jclass type,
    jobject a, jobject b
    /*...*/
)
{
    jclass cls = (env)->GetObjectClass (a);
    jmethodID integerToInt = (env)->GetMethodID(cls, "intValue", "()I");
    jint result = (env)->CallIntMethod(a, integerToInt);
}

static jobject gOnInteractionCallback = NULL;
extern "C"
JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_setOnInteractionCallbackNative
(
    JNIEnv *env,
    jclass type,
    jobject callback
)
{
    if (!gApp) return;

    if (!gJVM) env->GetJavaVM(&gJVM);
    gOnInteractionCallback = env->NewGlobalRef(callback);

    gApp->SetOnInteractionCallback([env](std::string message){
        // gJVM->AttachCurrentThread(const_cast<JNIEnv**>(&env), NULL);
        jclass cbClass = env->GetObjectClass(gOnInteractionCallback);

        int byteCount = message.length();
        const jbyte* pNativeMessage = reinterpret_cast<const jbyte*>(message.c_str());
        jbyteArray bytes = env->NewByteArray(byteCount);
        env->SetByteArrayRegion(bytes, 0, byteCount, pNativeMessage);

        // find the Charset.forName method:
        //   javap -s java.nio.charset.Charset | egrep -A2 "forName"
        jclass charsetClass = env->FindClass("java/nio/charset/Charset");
        jmethodID forName = env->GetStaticMethodID(
                charsetClass, "forName", "(Ljava/lang/String;)Ljava/nio/charset/Charset;");
        jstring utf8 = env->NewStringUTF("UTF-8");
        jobject charset = env->CallStaticObjectMethod(charsetClass, forName, utf8);

        // find a String constructor that takes a Charset:
        //   javap -s java.lang.String | egrep -A2 "String\(.*charset"
        jclass stringClass = env->FindClass("java/lang/String");
        jmethodID ctor = env->GetMethodID(
                stringClass, "<init>", "([BLjava/nio/charset/Charset;)V");

        jstring jMessage = reinterpret_cast<jstring>(
                env->NewObject(stringClass, ctor, bytes, charset));


        jmethodID jonChangeCb = env->GetMethodID(cbClass, "onInteract", "(Ljava/lang/String;)V");
        env->CallVoidMethod(gOnInteractionCallback, jonChangeCb, jMessage);
        //  gJVM->DetachCurrentThread();
    });
}

extern "C"
JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_onKeyNative
(
    JNIEnv *env,
    jclass type,
    jint keyCode
)
{
    if (gApp)
        gApp->OnKey(static_cast<e3::EKey>(keyCode), 0, gKeys->GetCharacter(static_cast<e3::EKey>(keyCode)));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_onKeyCharNative
(
    JNIEnv *env,
    jclass type,
    jchar c
)
{
    if (gApp)
        gApp->OnKey(/*static_cast<e3::EKey>(keyCode)*/e3::EKey::KeyUnknown, 0, /*gKeys->GetCharacter(static_cast<e3::EKey>(keyCode))*/c);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_carbon_element3d_e3View_onBackButtonPressedNative
(
    JNIEnv *env,
    jclass type
)
{
    if (gApp) return gApp->OnBack();
    return false;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_SetKeyboardHeightNative
(
    JNIEnv *env,
    jclass type,
    jint height
)
{
    if (gApp)
        gApp->SetKeyboardHeight(static_cast<int>(height));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_carbon_element3d_e3View_SetImageGalleryResultPathNative
(
    JNIEnv *env,
    jclass type,
    jstring path
)
{
    if (!gApp) return;
    gApp->SetImageGalleryResultPath(e3::Android::JniEnv::Get()->JStringToStdString(path));
}