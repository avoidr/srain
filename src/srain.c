/**
 * @file main.c
 * @brief main function here
 * @author Shengyu Zhang <silverrainz@outlook.com>
 * @version 1.0
 * @date 2016-03-01
 */

#define __LOG_ON

#include <sys/stat.h>
#include <gtk/gtk.h>
#include <errno.h>
#include <signal.h>

#include "srv.h"
#include "sui.h"

#include "srain_app.h"

#include "i18n.h"
#include "log.h"
#include "plugin.h"
#include "file_helper.h"

void quit(){
    plugin_finalize();

#ifdef IRC_TEST
    srv_finalize();
#endif

    exit(0);
}

int main(int argc, char **argv){
    create_user_file();
    signal(SIGINT, quit);

    i18n_init();
    plugin_init();

    sui_main_loop(argc, argv);

    quit();

    return 0;
}