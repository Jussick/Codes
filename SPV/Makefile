include ../../Makefile.head

BINARY=SPVSynchSer SPVSynchCli WinUserCli AccountCli PwdQuery mycli
LIBS=libunionpwdpush_s.so
LIBLD=-L../../lib64 -L/usr/lib64/mysql -lunionbox_s -lunionlog_s -lunionlic_s -lunionsock_s -lunionrandom_s -lossp-uuid -lunioncodec_s -lunionencrypt_s -lunionxml_s -lxml2 -luniondb_s -lmysqlclient -lnnz10 -locci -lclntsh -lunionevent_s -lunioncommcli_s -lunionerror_s -luniongettext_s -lunionSM2 -lunionsso_s -luniondb_s

all:$(BINARY) $(LIBS)

SyncUserReceiver.o: SyncUserReceiver.c
	$(CC) $(CFLAGS) -I../../include -D'LOGFILE="rsyncuser.log"' -c $^

SPVSynchSer: server.c keyhandle.c common.c AccountCli.c acchandle.c SPVPwdPushSer.c SyncUserReceiver.o
	$(CC) $(CFLAGS) -I../../include -o $@ $^ $(LIBLD) 
	cp -a $@ ../../bin/
	cp -a spvsynchd.service ../../systemd/

SPVSynchCli: cli.c keyrqt.c acccli.c pwdrqt.c common.c chain.c
	$(CC) $(CFLAGS) -I../../include -o $@ $^ $(LIBLD) 
	cp -a $@ ../../bin/

WinUserCli:WinUserCli.c common.c keyrqt.c
	$(CC) -g $(CFLAGS) -I../../include -o $@ $^ $(LIBLD) -Wno-pointer-sign
	cp -a $@ ../../bin/
AccountCli:AccountCli.c
	$(CC) -g $(CFLAGS) -D__TEST_MAIN__ -I../../include -o $@ $^ $(LIBLD) -Wno-pointer-sign
	cp -a $@ ../../bin/

PwdQuery:pwdquery.c keyrqt.c common.c pwdrqt.c 
	$(CC) -o $@ -I../../include $^ $(LIBLD)

libunionpwdpush_s.so: SPVPwdPushCli.c common.c
	$(CC) $(CFLAGS) -DONLY_LIBRARY -I../../include -shared -fPIC -o $@ $^
	cp $@ ../../lib64/

mycli: client.c common.c keyrqt.c
	$(CC) $(CFLAGS) -I../../include -o $@ $^ $(LIBLD)

include ../../Makefile.tail
