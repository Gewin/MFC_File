#ifndef _MP_CONFIGFILE_H_
#define _MP_CONFIGFILE_H_

#define VALUE_LENGTH        50
#define SPACE_ASCII_CODE    32

int MPReadSTBProvider(LPTSTR value);
int MPWriteSTBProvider(LPCTSTR stbProvider);

int MPReadOperatorId(LPTSTR value);
int MPWriteOperatorId(LPCTSTR operatorId);

int MPReadHWId(LPTSTR value);
int MPWriteHWId(LPCTSTR hwId);

int MPReadProductId(LPTSTR value);
int MPWriteProductId(LPCTSTR productId);

int MPReadSWId(LPTSTR value);
int MPWriteSWId(LPCTSTR swId);

int MPReadHWModel(LPTSTR value);
int MPWriteHWModel(LPCTSTR hwModel);

int MPReadSWModel(LPTSTR value);
int MPWriteSWModel(LPCTSTR swModel);

int MPReadHWConfig(LPTSTR value);
int MPWriteHWConfig(LPCTSTR hwConfig);

int MPReadYearWeek(LPTSTR value);
int MPWriteYearWeek(LPCTSTR yearWeek);

int MPReadManufacturerId(LPTSTR value);
int MPWriteManufacturerId(LPCTSTR manufacturerId);

int MPReadHWVersion(LPTSTR value);
int MPWriteHWVersion(LPCTSTR hwVersion);

int MPReadSTBSN(LPTSTR value);
int MPWriteSTBSN(LPCTSTR stbSN);


/* commond for operator the config file */
int MPReadCommond(LPTSTR value);



#endif