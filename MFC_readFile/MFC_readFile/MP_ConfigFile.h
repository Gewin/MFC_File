#ifndef _MP_CONFIGFILE_H_
#define _MP_CONFIGFILE_H_


int MPReadSTBProvider(char *value);
int MPWriteSTBProvider(char *stbProvider);

char *MPReadOperatorId(void);
void  MPWriteOperatorId(char *operatorId);

char *MPReadHWId(void);
void  MPWriteHWId(char *hwId);

char *MPReadProductId(void);
void  MPWriteProductId(char *productId);

char *MPReadSWId(void);
void  MPWriteSWId(char *swId);

char *MPReadHWModel(void);
void  MPWriteHWModel(char *hwModel);

char *MPReadSWModel(void);
void  MPWriteSWModel(char *swModel);

char *MPReadHWConfig(void);
void  MPWriteHWConfig(char *hwConfig);

char *MPReadYearWeek(void);
void  MPWriteYearWeek(char *yearWeek);

char *MPReadManufacturerId(void);
void  MPWriteManufacturerId(char *manufacturerId);

char *MPReadHWVersion(void);
void  MPWriteHWVersion(char *hwVersion);

char *MPReadSTBSN(void);
void  MPWriteSTBSN(char *stbSN);


/* commond for operator the config file */
char *MPReadCommond(void);



#endif