//C file
/***********************************************
#
#      Filename: redistest.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 一些hiredis库中接口的基本用法，做到C与Redis数据库的交互。
#        Create: 2019-03-20 15:12:43
#**********************************************/

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <assert.h>
#include <hiredis/hiredis.h> //redis C接口库

#define REDIS_HOST        "127.0.0.1"
#define REDIS_PORT        6379

redisContext *g_ctx = NULL;

int Redis_init()
{
    redisContext *c = NULL;
    c = redisConnect(REDIS_HOST, REDIS_PORT);
    if (NULL == c || c->err) {
        if(c) {
            printf("Redis [%s:%d], Error:[%s]\n", REDIS_HOST, REDIS_PORT, c->errstr);
            redisFree(c);
        } else {
            printf("Redis [%s:%d] failure\n", REDIS_HOST, REDIS_PORT);
        }
        return -1;
    }
    g_ctx = c;

    return 0;
}

void Redis_free()
{
    if (g_ctx) {
        redisFree(g_ctx);
    }
    g_ctx = NULL;
}

int Redis_test(const char *cmd)
{
    size_t i = 0;
    redisReply *r = NULL;
    if (NULL == cmd) {
        return -1;
    }

    printf("%s\n", cmd);

    r = (redisReply *)redisCommand(g_ctx, cmd);
    if (NULL == r) {
        printf("Error[%d:%s]", g_ctx->err, g_ctx->errstr);
        return -1;
    }

    printf("type: %d\n", r->type);
    switch(r->type) {
    case REDIS_REPLY_STATUS:
        printf("type:%s, reply->len:%ld reply->str:%s\n", "REDIS_REPLY_STATUS", r->len, r->str);
        break;
    case REDIS_REPLY_ERROR:
        printf("type:%s, reply->len:%ld reply->str:%s\n", "REDIS_REPLY_ERROR", r->len, r->str);
        break;
    case REDIS_REPLY_INTEGER:
        printf("type:%s, reply->integer:%lld\n", "REDIS_REPLY_INTEGER", r->integer);
        break;
    case REDIS_REPLY_NIL:
        printf("type:%s, no data\n", "REDIS_REPLY_NIL");
        break;
    case REDIS_REPLY_STRING:
        printf("type:%s, reply->len:%ld reply->str:%s\n", "REDIS_REPLY_STRING", r->len, r->str);
        break;
    case REDIS_REPLY_ARRAY:
        printf("type:%s, reply->elements:%ld\n", "REDIS_REPLY_ARRAY", r->elements);
        for (i = 0; i < r->elements; i++) {
            printf("%ld: %s\n", i, r->element[i]->str);
        }
        break;
    default:
        printf("unkonwn type:%d\n", r->type);
        break;
    }

    /*release reply and context */
    freeReplyObject(r);
    return 0;
}

int main()
{
    const char *cmd = NULL;

    /* init redis */
    if (Redis_init()) {
        return -1;
    }

    /* 1: SET<--->GET */
    printf("SET<--->GET\n");
    cmd = "set foo bar";
    Redis_test(cmd);
    cmd = "get foo";
    Redis_test(cmd);

    /* 2: SADD<--->SMEMBERS */
    printf("\nSADD<--->SMEMBERS\n");
    cmd = "SADD namelist jack lily lucy tom";
    Redis_test(cmd);
    cmd = "SMEMBERS namelist";
    Redis_test(cmd);

    /* 3: .....*/

    /* free redis context */
    Redis_free();

    return 0;
}
