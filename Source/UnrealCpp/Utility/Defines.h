#pragma once

#define CheckNull(p) {if(p==NULL) return;}
#define CheckNullResult(p, result) {if(p == NULL) return result;}

#define CheckTrue(p) {if(p == true) return;}
#define CheckTrueResult(p, result) {if(p == NULL) return result;}