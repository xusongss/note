

#ifdef __cplusplus

class IEncoder 
{
public:
	virtual int Initialize () = 0;
	
	virtual int EncodeFrame ()= 0;
	
	virtual int SetOption ()= 0;

	virtual int GetOption ()= 0;

	virtual ~IEncoder(){};
};

extern "C"
{
#else

	typedef struct _IEncoder IEncoder_t;
	typedef const IEncoder_t* IEncoder;
	struct _IEncoder
	{

		int (*Initialize) (IEncoder*);
	
		int (*EncodeFrame) (IEncoder*);
	
		int (*SetOption) (IEncoder*);

		int (*GetOption) (IEncoder*);
	};

	


#endif
	typedef enum
	{
		IENCONDE_TYPE_H264,
		IENCONDE_TYPE_OPH264,
		IENCONDE_TYPE_X264,
		IENCONDE_TYPE_MAX
	}IENCONDE_TYPE_T;
	int  CreateEncoder (IEncoder** ppEncoder, IENCONDE_TYPE_T type);
#ifdef __cplusplus
}
#endif





