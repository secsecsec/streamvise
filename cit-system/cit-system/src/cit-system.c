
/* 
 * Copyright (c) 2008-2012, Andy Bierman, All Rights Reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *

*** Generated by yangdump 2.2.1731

    Combined SIL module
    module cit-system
    revision 2012-04-11
    namespace http://netconfcentral.org/ns/cit-system
    organization ConnectIT

 */

#include <xmlstring.h>

#include "procdefs.h"
#include "agt.h"
#include "agt_cb.h"
#include "agt_not.h"
#include "agt_rpc.h"
#include "agt_timer.h"
#include "agt_util.h"
#include "dlq.h"
#include "ncx.h"
#include "ncx_feature.h"
#include "ncxmod.h"
#include "ncxtypes.h"
#include "rpc.h"
#include "ses.h"
#include "status.h"
#include "val.h"
#include "val_util.h"
#include "xml_util.h"
#include "cit-system.h"

/* module static variables */
static ncx_module_t *cit_system_mod;
static obj_template_t *system_reboot_obj;
static obj_template_t *get_live_conn_obj;
static obj_template_t *live_conn_obj;

/* put your static variables here */

/********************************************************************
* FUNCTION y_cit_system_init_static_vars
* 
* initialize module static variables
* 
********************************************************************/
static void y_cit_system_init_static_vars (void)
{
    cit_system_mod = NULL;
    system_reboot_obj = NULL;
    get_live_conn_obj = NULL;
    live_conn_obj = NULL;

    /* init your static variables here */

} /* y_cit_system_init_static_vars */


/********************************************************************
* FUNCTION y_cit_system_system_reboot_validate
* 
* RPC validation phase
* All YANG constraints have passed at this point.
* Add description-stmt checks in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_cit_system_system_reboot_validate (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
    status_t res = NO_ERR;
    val_value_t *errorval = NULL;


    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_OPERATION,
            res,
            methnode,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* y_cit_system_system_reboot_validate */


/********************************************************************
* FUNCTION y_cit_system_system_reboot_invoke
* 
* RPC invocation phase
* All constraints have passed at this point.
* Call device instrumentation code in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_cit_system_system_reboot_invoke (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
    status_t res = NO_ERR;


    /* remove the next line if scb is used */
    (void)scb;

    /* remove the next line if msg is used */
    (void)msg;

    /* remove the next line if methnode is used */
    (void)methnode;

    /* invoke your device instrumentation code here */

    printf("\n****    Running command: sudo reboot\n");
    runsystem("sudo reboot"); //Send command for running

    return res;

} /* y_cit_system_system_reboot_invoke */


/********************************************************************
* FUNCTION y_cit_system_get_live_conn_validate
* 
* RPC validation phase
* All YANG constraints have passed at this point.
* Add description-stmt checks in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_cit_system_get_live_conn_validate (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
    status_t res = NO_ERR;
    val_value_t *errorval = NULL;


    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_OPERATION,
            res,
            methnode,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* y_cit_system_get_live_conn_validate */


/********************************************************************
* FUNCTION y_cit_system_get_live_conn_invoke
* 
* RPC invocation phase
* All constraints have passed at this point.
* Call device instrumentation code in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_cit_system_get_live_conn_invoke (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
    status_t res = NO_ERR;


    /* remove the next line if scb is used */
    (void)scb;

    /* remove the next line if msg is used */
    (void)msg;

    /* remove the next line if methnode is used */
    (void)methnode;

    /* invoke your device instrumentation code here */
    
	char conn[512];
	char tmpconn[512];
        size_t len = 0;
	char *line = NULL;
	int exitcounter=0;

	FILE *file;
	printf("**TRYING to get uid\n");
	printf("**UID: %i\n",getuid());
	printf("**EUID: %i\n",geteuid());

	setreuid(-1,0);  //Set Effective UserID to 0 (root). Leave Real UserID unchanged
	printf("**TRYING to get uid\n");
	printf("**UID: %i\n",getuid());
	printf("**EUID: %i\n",geteuid());

	runsystem("sudo cat /proc/net/ip_conntrack > /tmp/conn"); //Copy conntrack as a superuser to a simple file

	if (file = fopen("/tmp/conn","r") ){// Open the simple file
	        while ((getline(&line, &len, file)) != -1)  //Scan each line
     		{
			sprintf(tmpconn, "%s", &line[0]);
//			strcat(conn,tmpconn); //Add the line to the conn string to be sent back to the client.
			y_cit_system_live_conn_send (tmpconn); //Send the connections text to the notification
		}
		fclose(file);
		runsystem("rm /tmp/conn"); //Remove the tmp file
	}else{
		printf("Error opening file /proc/net/ip_conntrack!\n");
		sprintf(conn, "Error opening file /proc/net/ip_conntrack!");
	}
    	return res;

} /* y_cit_system_get_live_conn_invoke */


/********************************************************************
* FUNCTION y_cit_system_live_conn_send
* 
* Send a y_cit_system_live_conn notification
* Called by your code when notification event occurs
* 
********************************************************************/
void y_cit_system_live_conn_send (
    const xmlChar *live_conn)
{
    agt_not_msg_t *notif;
    val_value_t *parmval;
    status_t res = NO_ERR;


    if (LOGDEBUG) {
        log_debug("\nGenerating <live-conn> notification");
    }
    
    notif = agt_not_new_notification(live_conn_obj);
    if (notif == NULL) {
        log_error("\nError: malloc failed, cannot send "
        "<live-conn> notification");
        return;
    }
    
    /* add live_conn to payload */
    parmval = agt_make_leaf(
        live_conn_obj,
        y_cit_system_N_live_conn,
        live_conn,
        &res);
    if (parmval == NULL) {
        log_error(
            "\nError: make leaf failed (%s), cannot send "
            "<live-conn> notification",
            get_error_string(res));
    } else {
        agt_not_add_to_payload(notif, parmval);
    }
    
    agt_not_queue_notification(notif);
    
} /* y_cit_system_live_conn_send */

/********************************************************************
* FUNCTION y_cit_system_init
* 
* initialize the cit-system server instrumentation library
* 
* INPUTS:
*    modname == requested module name
*    revision == requested version (NULL for any)
* 
* RETURNS:
*     error status
********************************************************************/
status_t y_cit_system_init (
    const xmlChar *modname,
    const xmlChar *revision)
{
    status_t res = NO_ERR;
    agt_profile_t *agt_profile = agt_get_profile();

    y_cit_system_init_static_vars();

    /* change if custom handling done */
    if (xml_strcmp(modname, y_cit_system_M_cit_system)) {
        return ERR_NCX_UNKNOWN_MODULE;
    }

    if (revision && xml_strcmp(revision, y_cit_system_R_cit_system)) {
        return ERR_NCX_WRONG_VERSION;
    }
    res = ncxmod_load_module(
        y_cit_system_M_cit_system,
        y_cit_system_R_cit_system,
        &agt_profile->agt_savedevQ,
        &cit_system_mod);
    if (res != NO_ERR) {
        return res;
    }

    system_reboot_obj = ncx_find_object(
        cit_system_mod,
        y_cit_system_N_system_reboot);
    if (cit_system_mod == NULL) {
        return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
    }
    get_live_conn_obj = ncx_find_object(
        cit_system_mod,
        y_cit_system_N_get_live_conn);
    if (cit_system_mod == NULL) {
        return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
    }
    live_conn_obj = ncx_find_object(
        cit_system_mod,
        y_cit_system_N_live_conn);
    if (cit_system_mod == NULL) {
        return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
    }
    res = agt_rpc_register_method(
        y_cit_system_M_cit_system,
        y_cit_system_N_system_reboot,
        AGT_RPC_PH_VALIDATE,
        y_cit_system_system_reboot_validate);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_rpc_register_method(
        y_cit_system_M_cit_system,
        y_cit_system_N_system_reboot,
        AGT_RPC_PH_INVOKE,
        y_cit_system_system_reboot_invoke);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_rpc_register_method(
        y_cit_system_M_cit_system,
        y_cit_system_N_get_live_conn,
        AGT_RPC_PH_VALIDATE,
        y_cit_system_get_live_conn_validate);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_rpc_register_method(
        y_cit_system_M_cit_system,
        y_cit_system_N_get_live_conn,
        AGT_RPC_PH_INVOKE,
        y_cit_system_get_live_conn_invoke);
    if (res != NO_ERR) {
        return res;
    }

    /* put your module initialization code here */
    
    return res;
} /* y_cit_system_init */

/********************************************************************
* FUNCTION y_cit_system_init2
* 
* SIL init phase 2: non-config data structures
* Called after running config is loaded
* 
* RETURNS:
*     error status
********************************************************************/
status_t y_cit_system_init2 (void)
{
    status_t res = NO_ERR;

    /* put your init2 code here */

    return res;
} /* y_cit_system_init2 */

/********************************************************************
* FUNCTION y_cit_system_cleanup
*    cleanup the server instrumentation library
* 
********************************************************************/
void y_cit_system_cleanup (void)
{
    
    agt_rpc_unregister_method(
        y_cit_system_M_cit_system,
        y_cit_system_N_system_reboot);
    
    agt_rpc_unregister_method(
        y_cit_system_M_cit_system,
        y_cit_system_N_get_live_conn);
    /* put your cleanup code here */
    
} /* y_cit_system_cleanup */

/* END cit_system.c */
