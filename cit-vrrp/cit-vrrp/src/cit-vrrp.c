
/* 
 * Copyright (c) 2013, Chris Mavrakis, All Rights Reserved.
 * Full license can be found in LICENSE file.

*** Generated by yangdump 2.2-2

    Combined SIL module
    module cit-vrrp
    revision 2012-04-13
    namespace http://netconfcentral.org/ns/cit-vrrp
    organization ConnectIT

 */

#include <xmlstring.h>

#include "procdefs.h"
#include "agt.h"
#include "agt_cb.h"
#include "agt_timer.h"
#include "agt_util.h"
#include "dlq.h"
#include "ncx.h"
#include "ncx_feature.h"
#include "ncxmod.h"
#include "ncxtypes.h"
#include "status.h"
#include "cit-vrrp.h"
#include "cit-helper.h"

/* module static variables */
static ncx_module_t *cit_vrrp_mod;
static obj_template_t *vrrp_obj;
static val_value_t *vrrp_val;

/* put your static variables here */

/********************************************************************
* FUNCTION y_cit_vrrp_init_static_vars
* 
* initialize module static variables
* 
********************************************************************/
static void y_cit_vrrp_init_static_vars (void)
{
    cit_vrrp_mod = NULL;
    vrrp_obj = NULL;
    vrrp_val = NULL;

    /* init your static variables here */

} /* y_cit_vrrp_init_static_vars */


/********************************************************************
* FUNCTION cit_vrrp_vrrp_rule_entryno_edit
* 
* Edit database object callback
* Path: /vrrp/rule/entryno
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cit_vrrp_vrrp_rule_entryno_edit (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
    status_t res = NO_ERR;
    val_value_t *errorval = (curval) ? curval : newval;

    if (LOGDEBUG) {
        log_debug("\nEnter cit_vrrp_vrrp_rule_entryno_edit callback for %s phase",
            agt_cbtype_name(cbtyp));
    }

    switch (cbtyp) {
    case AGT_CB_VALIDATE:
        /* description-stmt validation here */
        break;
    case AGT_CB_APPLY:
        /* database manipulation done here */
        break;
    case AGT_CB_COMMIT:
        /* device instrumentation done here */
        switch (editop) {
        case OP_EDITOP_LOAD:
            break;
        case OP_EDITOP_MERGE:
            break;
        case OP_EDITOP_REPLACE:
            break;
        case OP_EDITOP_CREATE:
            break;
        case OP_EDITOP_DELETE:
            break;
        default:
            res = SET_ERROR(ERR_INTERNAL_VAL);
        }
        break;
    case AGT_CB_ROLLBACK:
        /* undo device instrumentation here */
        break;
    default:
        res = SET_ERROR(ERR_INTERNAL_VAL);
    }

    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_CONTENT,
            res,
            NULL,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* cit_vrrp_vrrp_rule_entryno_edit */


/********************************************************************
* FUNCTION cit_vrrp_vrrp_rule_interface_edit
* 
* Edit database object callback
* Path: /vrrp/rule/interface
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cit_vrrp_vrrp_rule_interface_edit (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
    status_t res = NO_ERR;
    val_value_t *errorval = (curval) ? curval : newval;

    if (LOGDEBUG) {
        log_debug("\nEnter cit_vrrp_vrrp_rule_interface_edit callback for %s phase",
            agt_cbtype_name(cbtyp));
    }

    switch (cbtyp) {
    case AGT_CB_VALIDATE:
        /* description-stmt validation here */
        break;
    case AGT_CB_APPLY:
        /* database manipulation done here */
        break;
    case AGT_CB_COMMIT:
        /* device instrumentation done here */
        switch (editop) {
        case OP_EDITOP_LOAD:
            break;
        case OP_EDITOP_MERGE:
            break;
        case OP_EDITOP_REPLACE:
            break;
        case OP_EDITOP_CREATE:
            break;
        case OP_EDITOP_DELETE:
            break;
        default:
            res = SET_ERROR(ERR_INTERNAL_VAL);
        }
        break;
    case AGT_CB_ROLLBACK:
        /* undo device instrumentation here */
        break;
    default:
        res = SET_ERROR(ERR_INTERNAL_VAL);
    }

    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_CONTENT,
            res,
            NULL,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* cit_vrrp_vrrp_rule_interface_edit */


/********************************************************************
* FUNCTION cit_vrrp_vrrp_rule_vrid_edit
* 
* Edit database object callback
* Path: /vrrp/rule/vrid
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cit_vrrp_vrrp_rule_vrid_edit (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
    status_t res = NO_ERR;
    val_value_t *errorval = (curval) ? curval : newval;

    if (LOGDEBUG) {
        log_debug("\nEnter cit_vrrp_vrrp_rule_vrid_edit callback for %s phase",
            agt_cbtype_name(cbtyp));
    }

    switch (cbtyp) {
    case AGT_CB_VALIDATE:
        /* description-stmt validation here */
        break;
    case AGT_CB_APPLY:
        /* database manipulation done here */
        break;
    case AGT_CB_COMMIT:
        /* device instrumentation done here */
        switch (editop) {
        case OP_EDITOP_LOAD:
            break;
        case OP_EDITOP_MERGE:
            break;
        case OP_EDITOP_REPLACE:
            break;
        case OP_EDITOP_CREATE:
            break;
        case OP_EDITOP_DELETE:
            break;
        default:
            res = SET_ERROR(ERR_INTERNAL_VAL);
        }
        break;
    case AGT_CB_ROLLBACK:
        /* undo device instrumentation here */
        break;
    default:
        res = SET_ERROR(ERR_INTERNAL_VAL);
    }

    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_CONTENT,
            res,
            NULL,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* cit_vrrp_vrrp_rule_vrid_edit */


/********************************************************************
* FUNCTION cit_vrrp_vrrp_rule_priority_edit
* 
* Edit database object callback
* Path: /vrrp/rule/priority
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cit_vrrp_vrrp_rule_priority_edit (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
    status_t res = NO_ERR;
    val_value_t *errorval = (curval) ? curval : newval;

    if (LOGDEBUG) {
        log_debug("\nEnter cit_vrrp_vrrp_rule_priority_edit callback for %s phase",
            agt_cbtype_name(cbtyp));
    }

    switch (cbtyp) {
    case AGT_CB_VALIDATE:
        /* description-stmt validation here */
        break;
    case AGT_CB_APPLY:
        /* database manipulation done here */
        break;
    case AGT_CB_COMMIT:
        /* device instrumentation done here */
        switch (editop) {
        case OP_EDITOP_LOAD:
            break;
        case OP_EDITOP_MERGE:
            break;
        case OP_EDITOP_REPLACE:
            break;
        case OP_EDITOP_CREATE:
            break;
        case OP_EDITOP_DELETE:
            break;
        default:
            res = SET_ERROR(ERR_INTERNAL_VAL);
        }
        break;
    case AGT_CB_ROLLBACK:
        /* undo device instrumentation here */
        break;
    default:
        res = SET_ERROR(ERR_INTERNAL_VAL);
    }

    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_CONTENT,
            res,
            NULL,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* cit_vrrp_vrrp_rule_priority_edit */


/********************************************************************
* FUNCTION cit_vrrp_vrrp_rule_ip_address_edit
* 
* Edit database object callback
* Path: /vrrp/rule/ip-address
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cit_vrrp_vrrp_rule_ip_address_edit (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
    status_t res = NO_ERR;
    val_value_t *errorval = (curval) ? curval : newval;

    if (LOGDEBUG) {
        log_debug("\nEnter cit_vrrp_vrrp_rule_ip_address_edit callback for %s phase",
            agt_cbtype_name(cbtyp));
    }

    switch (cbtyp) {
    case AGT_CB_VALIDATE:
        /* description-stmt validation here */
        break;
    case AGT_CB_APPLY:
        /* database manipulation done here */
        break;
    case AGT_CB_COMMIT:
        /* device instrumentation done here */
        switch (editop) {
        case OP_EDITOP_LOAD:
            break;
        case OP_EDITOP_MERGE:
            break;
        case OP_EDITOP_REPLACE:
            break;
        case OP_EDITOP_CREATE:
            break;
        case OP_EDITOP_DELETE:
            break;
        default:
            res = SET_ERROR(ERR_INTERNAL_VAL);
        }
        break;
    case AGT_CB_ROLLBACK:
        /* undo device instrumentation here */
        break;
    default:
        res = SET_ERROR(ERR_INTERNAL_VAL);
    }

    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_CONTENT,
            res,
            NULL,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* cit_vrrp_vrrp_rule_ip_address_edit */


/********************************************************************
* FUNCTION cit_vrrp_vrrp_rule_edit
* 
* Edit database object callback
* Path: /vrrp/rule
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cit_vrrp_vrrp_rule_edit (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
    status_t res = NO_ERR;
    val_value_t *errorval = (curval) ? curval : newval;

    if (LOGDEBUG) {
        log_debug("\nEnter cit_vrrp_vrrp_rule_edit callback for %s phase",
            agt_cbtype_name(cbtyp));
    }

    switch (cbtyp) {
    case AGT_CB_VALIDATE:
        /* description-stmt validation here */
        break;
    case AGT_CB_APPLY:
        /* database manipulation done here */
        break;
    case AGT_CB_COMMIT:
        {
		      val_value_t *tmpval; //Will hold the data node that we're processing each time
		      char cmd[512]; //The command to be run
		      char tmpcmd[512]; //Var to temporary hold the command
		      strcpy (cmd,"vrrpd "); //The beginning of the command to be run

		      //Get the interface name
		      tmpval = val_match_child(newval, xmlCharStrdup("cit-vrrp"), xmlCharStrdup("interface")); //Search for element
		      if (tmpval != NULL) {
			      sprintf(tmpcmd, "-i %s ", VAL_STRING(tmpval)); //Get the element value
		        strcat(cmd,tmpcmd); //Append the new part to the command
		      }

		      //Get vrid
		      tmpval = val_match_child(newval, xmlCharStrdup("cit-vrrp"), xmlCharStrdup("vrid")); //Search for element
		      if (tmpval != NULL) {
			      sprintf(tmpcmd, "-v %i ", VAL_INT(tmpval)); //Get the element value
		        strcat(cmd,tmpcmd); //Append the new part to the command
		      }

		      //Get priority
		      tmpval = val_match_child(newval, xmlCharStrdup("cit-vrrp"), xmlCharStrdup("priority")); //Search for element
		      if (tmpval != NULL) { 
			      sprintf(tmpcmd, "-p %i ", VAL_INT(tmpval)); //Get the element value
		        strcat(cmd,tmpcmd); //Append the new part to the command
		      }

		      //Get destination IP
		      tmpval = val_match_child(newval, xmlCharStrdup("cit-vrrp"), xmlCharStrdup("ip-address")); //Search for element
		      if (tmpval != NULL) {
			      sprintf(tmpcmd, "%s ", VAL_STRING(tmpval)); //Get the element value
		        strcat(cmd,tmpcmd); //Append the new part to the command
		      }

		      printf("****    Running command: %s\n", cmd);
		      runsystem(cmd); //Send command for running

        	switch (editop) {
        	case OP_EDITOP_LOAD:
        	    break;
        	case OP_EDITOP_MERGE:
        	    break;
        	case OP_EDITOP_REPLACE:
        	    break;
        	case OP_EDITOP_CREATE:
        	    break;
        	case OP_EDITOP_DELETE:
        	    break;
        	default:
        	    res = SET_ERROR(ERR_INTERNAL_VAL);
        	}
	}
        break;
    case AGT_CB_ROLLBACK:
        /* undo device instrumentation here */
        break;
    default:
        res = SET_ERROR(ERR_INTERNAL_VAL);
    }

    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_CONTENT,
            res,
            NULL,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* cit_vrrp_vrrp_rule_edit */


/********************************************************************
* FUNCTION cit_vrrp_vrrp_edit
* 
* Edit database object callback
* Path: /vrrp
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cit_vrrp_vrrp_edit (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
    status_t res = NO_ERR;
    val_value_t *errorval = (curval) ? curval : newval;

    if (LOGDEBUG) {
        log_debug("\nEnter cit_vrrp_vrrp_edit callback for %s phase",
            agt_cbtype_name(cbtyp));
    }

    switch (cbtyp) {
    case AGT_CB_VALIDATE:
        /* description-stmt validation here */
        break;
    case AGT_CB_APPLY:
        /* database manipulation done here */
        break;
    case AGT_CB_COMMIT:
        /* device instrumentation done here */
        switch (editop) {
        case OP_EDITOP_LOAD:
            break;
        case OP_EDITOP_MERGE:
            break;
        case OP_EDITOP_REPLACE:
            break;
        case OP_EDITOP_CREATE:
            break;
        case OP_EDITOP_DELETE:
            break;
        default:
            res = SET_ERROR(ERR_INTERNAL_VAL);
        }

        if (res == NO_ERR) {
            res = agt_check_cache(&vrrp_val, newval, curval, editop);
        }
        
        break;
    case AGT_CB_ROLLBACK:
        /* undo device instrumentation here */
        break;
    default:
        res = SET_ERROR(ERR_INTERNAL_VAL);
    }

    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_CONTENT,
            res,
            NULL,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* cit_vrrp_vrrp_edit */

/********************************************************************
* FUNCTION y_cit_vrrp_init
* 
* initialize the cit-vrrp server instrumentation library
* 
* INPUTS:
*    modname == requested module name
*    revision == requested version (NULL for any)
* 
* RETURNS:
*     error status
********************************************************************/
status_t y_cit_vrrp_init (
    const xmlChar *modname,
    const xmlChar *revision)
{
    status_t res = NO_ERR;
    agt_profile_t *agt_profile = agt_get_profile();

    y_cit_vrrp_init_static_vars();

    /* change if custom handling done */
    if (xml_strcmp(modname, y_cit_vrrp_M_cit_vrrp)) {
        return ERR_NCX_UNKNOWN_MODULE;
    }

    if (revision && xml_strcmp(revision, y_cit_vrrp_R_cit_vrrp)) {
        return ERR_NCX_WRONG_VERSION;
    }
    res = ncxmod_load_module(
        y_cit_vrrp_M_cit_vrrp,
        y_cit_vrrp_R_cit_vrrp,
        &agt_profile->agt_savedevQ,
        &cit_vrrp_mod);
    if (res != NO_ERR) {
        return res;
    }

    vrrp_obj = ncx_find_object(
        cit_vrrp_mod,
        y_cit_vrrp_N_vrrp);
    if (cit_vrrp_mod == NULL) {
        return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
    }
    res = agt_cb_register_callback(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp",
        y_cit_vrrp_R_cit_vrrp,
        cit_vrrp_vrrp_edit);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_cb_register_callback(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp/rule",
        y_cit_vrrp_R_cit_vrrp,
        cit_vrrp_vrrp_rule_edit);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_cb_register_callback(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp/rule/entryno",
        y_cit_vrrp_R_cit_vrrp,
        cit_vrrp_vrrp_rule_entryno_edit);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_cb_register_callback(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp/rule/interface",
        y_cit_vrrp_R_cit_vrrp,
        cit_vrrp_vrrp_rule_interface_edit);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_cb_register_callback(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp/rule/vrid",
        y_cit_vrrp_R_cit_vrrp,
        cit_vrrp_vrrp_rule_vrid_edit);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_cb_register_callback(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp/rule/priority",
        y_cit_vrrp_R_cit_vrrp,
        cit_vrrp_vrrp_rule_priority_edit);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_cb_register_callback(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp/rule/ip-address",
        y_cit_vrrp_R_cit_vrrp,
        cit_vrrp_vrrp_rule_ip_address_edit);
    if (res != NO_ERR) {
        return res;
    }

    /* put your module initialization code here */
    
    return res;
} /* y_cit_vrrp_init */

/********************************************************************
* FUNCTION y_cit_vrrp_init2
* 
* SIL init phase 2: non-config data structures
* Called after running config is loaded
* 
* RETURNS:
*     error status
********************************************************************/
status_t y_cit_vrrp_init2 (void)
{
    status_t res = NO_ERR;

    vrrp_val = agt_init_cache(
        y_cit_vrrp_M_cit_vrrp,
        y_cit_vrrp_N_vrrp,
        &res);
    if (res != NO_ERR) {
        return res;
    }

    /* put your init2 code here */

    return res;
} /* y_cit_vrrp_init2 */

/********************************************************************
* FUNCTION y_cit_vrrp_cleanup
*    cleanup the server instrumentation library
* 
********************************************************************/
void y_cit_vrrp_cleanup (void)
{
    agt_cb_unregister_callbacks(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp");

    agt_cb_unregister_callbacks(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp/rule");

    agt_cb_unregister_callbacks(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp/rule/entryno");

    agt_cb_unregister_callbacks(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp/rule/interface");

    agt_cb_unregister_callbacks(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp/rule/vrid");

    agt_cb_unregister_callbacks(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp/rule/priority");

    agt_cb_unregister_callbacks(
        y_cit_vrrp_M_cit_vrrp,
        (const xmlChar *)"/vrrp/rule/ip-address");

    /* put your cleanup code here */
    
} /* y_cit_vrrp_cleanup */

/* END cit_vrrp.c */
