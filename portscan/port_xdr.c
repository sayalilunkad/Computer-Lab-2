/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "port.h"

bool_t
xdr_input (XDR *xdrs, input *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->host, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->start))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->end))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_output (XDR *xdrs, output *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (1 +  100 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->total))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->portno, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->total);
			{
				register int *genp;

				for (i = 0, genp = objp->portno;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (1 +  100 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->total))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->portno, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			objp->total = IXDR_GET_LONG(buf);
			{
				register int *genp;

				for (i = 0, genp = objp->portno;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->total))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->portno, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_in (XDR *xdrs, in *objp)
{
	register int32_t *buf;

	 if (!xdr_input (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_out (XDR *xdrs, out *objp)
{
	register int32_t *buf;

	 if (!xdr_output (xdrs, objp))
		 return FALSE;
	return TRUE;
}
