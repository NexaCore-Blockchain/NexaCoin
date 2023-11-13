nano launch_NexaCore.sh
chmod +x launch_NexaCore.sh
sudo ufw allow 33553
./komodo-cli -ac_name=NexaCore addnode 10.0.2.15 add
./komodo-cli -ac_name=NexaCore addnode 192.168.100.19 add
 NexaCore-explorer-start.sh 
[ * ] Visit http://197.205.23.85:23166 from another computer to access the explorer after starting it
[ * ] Visit http://localhost:33553 on your computer to access the explorer after starting it
P
192.168.100.19

"address": "RBLMyt3EofsyDVBuCTSTbXbFXNXvJgbd8H",
  "scriptPubKey": "76a9141689c413d4d41ccbfb7f13f423af371a446fd09c88ac",
  "segid": 54,
  "ismine": true,
  "iswatchonly": false,
  "isscript": false,
  "pubkey": "032ff35eee03121c46ce4b193c8d200e51e51b840ad6a0793e3b0a4a26b814a7d7",
  "iscompressed": true,
  "account": ""
./komodod -ac_name=NexaCore -ac_supply=70000000 -ac_reward=700000000 -ac_halving=525600 pubkey=022f7a698561d657cf22e8a23996658e98a42ef0c096186f9e12add720fcbdfbc6 &