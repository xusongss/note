#include "c_api.h"
#include "stdio.h"
int main()
{
	int ii;
	IEncoder * enc;
	for(ii = IENCONDE_TYPE_H264; ii< IENCONDE_TYPE_MAX; ii++)
	{
		printf("\nCreateEncoder type=%d\n", ii);
		CreateEncoder(&enc, ii);
		(* enc)->Initialize(enc);
		(* enc)->EncodeFrame(enc);
		(* enc)->SetOption(enc);
		(* enc)->GetOption(enc);
	}
	return 0;
}
