#include "c_api.h"
#include "iostream"
using namespace std;


class H264Encoder  :public IEncoder 
{
public:
	H264Encoder();
	H264Encoder(string type)
	{
		this->type = type;
	};
	virtual ~H264Encoder();
	virtual int Initialize ();
	
	virtual int EncodeFrame ();
	
	virtual int SetOption ();

	virtual int GetOption ();
private:
	string type;
};
H264Encoder::H264Encoder()
{
	type=__FUNCTION__;
}
H264Encoder::~H264Encoder()
{
	
};
int H264Encoder::Initialize ()
{
	cout<<this->type<<"::"<<__FUNCTION__<<endl;
}

int H264Encoder::EncodeFrame ()
{
	cout<<this->type<<"::"<<__FUNCTION__<<endl;
}

int H264Encoder::SetOption ()
{
	cout<<this->type<<"::"<<__FUNCTION__<<endl;
}

int H264Encoder::GetOption ()
{
	cout<<this->type<<"::"<<__FUNCTION__<<endl;
}
//****************************************************************************************//
class OPH264Encoder : public H264Encoder
{
public:
	OPH264Encoder (): H264Encoder("OPH264Encoder"){};
	virtual ~OPH264Encoder (){};
};
//****************************************************************************************//
class X264Encoder : public H264Encoder
{
public:
	X264Encoder (): H264Encoder("X264Encoder"){};
	virtual ~X264Encoder (){};
};



int  CreateEncoder (IEncoder** ppEncoder, IENCONDE_TYPE_T type)
{
	switch(type)
	{
		case  IENCONDE_TYPE_H264:
			*ppEncoder = new H264Encoder();
			break;
		case  IENCONDE_TYPE_OPH264:
			*ppEncoder = new OPH264Encoder();
			break;
		case  IENCONDE_TYPE_X264:
			*ppEncoder = new X264Encoder();
			break;
		default:
			*ppEncoder = NULL;
			break;
	}
	if ((*ppEncoder) != NULL)
	{
		return 0;
	}

	return 1;
}

