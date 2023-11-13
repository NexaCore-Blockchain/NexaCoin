Managed DevelopmentPricingSolutionsBlogStart Building
Search articles:
How to build your own blockchain using Komodo
Blockchain
Komodo
Cryptocurrency
Blockchain Startup
Blockchain Development
Want to build your own asset chain and token? It’s easier than you might think, thanks to Komodo.

Want to build your own blockchain? It’s easier than it sounds.

Today, we will review how to build a private blockchain using the Komodo platform.
What is Komodo?

Komodo is a blockchain development platform with powerful features. (Hyperledger and Quorum are similar technologies).

The Komodo platform has it’s own blockchain with a currency named KMD. You can spin-off your own blockchain (asset chain) on the Komodo platform using the Komodo asset chain as a template.
History

In 2016, Komodo’s Lead Developer, James ‘jl777’ Lee, was working on a project called SuperNET on Nxt, one of the world’s very first blockchain platforms.

The Nxt team implemented major changes to the codebase without consulting any of the projects built on the Nxt platform. The changes broke SuperNET’s backend tech.

This event showed the limitations of the single-blockchain platform model. jl777 issued a Declaration of Independence in response and announced Komodo project. Komodo ICO raised a total of 2,639 BTC in November 2016.
Why Komodo? (And, other platform considerations)

Let analyze blockchain platforms. Bitcoin was the first generation blockchain optimized for security and value store on-chain. Next came Etherum, Waves, and Nxt where any developer could build decentralized apps while sharing a single chain. However, these platforms have problems like scalability and interoperability.

Komodo is a 3rd generation platform, where you can spin off your own blockchain (one like ethereum).

    If you’re interested in Etheruem blockchain development, Crowdbotics has a new ERC-20 scaffold that you deploy for free using the Crowdbotics app builder. Give it a try.

Komodo is secure and full of cutting-edge blockchain features. Every chain built using Komodo gets the full features of Komodo blockchain and supports technologies like smart contracts, zero-knowledge privacy, and atomic swap. Komodo prioritizes on 4 key properties.

    Security
    Scalability
    Interpretability
    Adaptability

Delayed proof of work (dPoW)

Komodo uses dPoW as its consensus protocol. Komodo’s dPoW leverages the hashrate of the Bitcoin network for security. Every 10 mints, the komodo blockchain’s snapshot gets saved on Bitcoin blockchain as a backup. This security feature also extends to asset chains being built on Komodo. So, Komodo takes a snapshot of all asset chains and also it’s own state. This snapshot is written into a block on the Bitcoin blockchain. This process is called notarization. There are 64 nodes always running to full fill this purpose.
What is asset Chain?

As per Komodo website:

    “The KMD chain serves as a master template from which every other blockchain in our ecosystem is generated. Independent blockchains on Komodo Platform are called assetchains, and each one is a runtime fork of the KMD chain. That means every asssetchain is endowed with zero-knowledge proof privacy features and the protection of dPoW security.”

Asset chains are private chains which have all the features of Komodo chain but they are independent of the other asset chains. The best part is that a single project can run multiple asset chains. They can also sync and talk to each other.
Benefits of having your own chain

There are many benefits of having your own chain. Let's discuss some of them.

    Scalability — Currently ethereum can process around 15 transactions per second. Every smart contract and DApp running on Ethereum is bound to this shared transaction speed. This is problematic as it removes apps from the equation which needs high volume transaction.
    **Security **— A bug on the main platform can bring the “Holy hell” on the whole ecosystem. If you are running a private asset chain you can isolate yourself from these problems.
    Interoperability —Two tokens on the same platform can’t be traded to each other without main platform token. For example, let’s assume token A and B running on the main platform which is token Z. You can’t exchange A → B without A → Z →B. Komodo solved this problem using atomic swaps.
    **More application **— Komodo currently supports 20K transactions per second and is working to scale to over a million transaction per/second. This opens a door for more use cases that can be covered using Komodo platform.
    Freedom of customization — Because your blockchain belongs to you, the limits of the platform are only limited by your imagination. A skilled developer can leverage the platform and build more customization into their asset chain.

How to create your Blockchain (Asset chain)

Now, let’s build our own chain called “Dragon” (can’t think of any better name).
Prerequisite

    Basic understanding of command line
    Basic understanding of networking
    Basic understanding of Git

Hardware Requirement

    2 Computers with the ability to open ports.
    At least 4GB RAM each
    At least 2 CPU cores each
    64-bit Operating System (Ubuntu 16.04 recommended)
    At least 20 GB of secondary memory

Before setting our own asset chain we need to Install Komodo itself, as the Komodo codebase works as a template for our asset chain.
Installing Komodo

Let’s install komodo. I will be using Google cloud for this purpose. If you have two systems then you can use them. We need to install Komodo in both of them. I am using a Debian system for this. If you are using window or OSX, follow the instructions here and here accordingly.

Installing dependencies

sudo apt-get update
sudo apt-get upgrade



sudo apt-get install build-essential pkg-config libc6-dev m4 g++-multilib autoconf libtool ncurses-dev unzip git python zlib1g-dev wget bsdmainutils automake libboost-all-dev libssl-dev libprotobuf-dev protobuf-compiler libgtest-dev libqt4-dev libqrencode-dev libdb++-dev ntp ntpdate vim software-properties-common curl libcurl4-gnutls-dev cmake clang

Install nanomsg

Nanomsg is a socket library that provides several common communication patterns. It aims to make the networking layer fast, scalable, and easy to use. Implemented in C, it works on a wide range of operating systems with no further dependencies.

cd ~
git clone https://github.com/nanomsg/nanomsg
cd nanomsg
cmake . -DNN_TESTS=OFF -DNN_ENABLE_DOC=OFF
make -j2
sudo make install
sudo ldconfig

This takes some time depending on your internet connection. Let it run in the background. Now it is time to install Komodo.

Installing Komodo

cd ~
git clone https://github.com/jl777/komodo
cd komodo
git checkout dev
./zcutil/fetch-params.sh
./zcutil/build.sh -j2

This will take some time. Let’s create a komodo.conf meanwhile. Open a new terminal window and run this.

cd ~
mkdir .komodo
cd .komodo
nano komodo.conf

Add the following lines to the komodo.conf file (replace rpcuser and rpcpassword)

rpcuser=username
rpcpassword=password
txindex=1
bind=127.0.0.1
rpcbind=127.0.0.1

Press CTRL+X and Y to save and exit nano editor.

Now you can start komodod daemon to sync with the network. This will take time.

cd ~
cd komodo
./src/komodod -addnode=78.47.196.146 -daemon

You will see some outputs in the terminal where you started the komodod daemon. You can check logs using below

cd ~/.komodo/
tail -f debug.log

Now as we installed komodo daemon komodod, we can now use komodo-cli to run commands. For example, run this:

cd ~/komodo/src/
./komodo-cli getinfo

You will see output like this.

{
    "version": 1000550,
    "protocolversion": 170002,
    "KMDversion": "0.1.0",
    "notarized": 186670,
    "notarizedhash": "000000308845da840ab9af6c1e09dc02f3118683df065b5ec00b05c9bd58cdae",
    "notarizedtxid": "6723a10ef4fceab230d4245305d1ed2a916e435abb83269c20daad9bbefd3f0e",
    "notarizedtxid_height": "mempool",
    "notarized_confirms": 0,
    "walletversion": 60000,
    "balance": 0,
    "interest": 0,
    "blocks": 186773,
    "longestchain": 308867,
    "timeoffset": 0,
    "tiptime": 1486411069,
    "connections": 8,
    "proxy": "",
    "difficulty": 1624278.62879530,
    "testnet": false,
    "keypoololdest": 1482746526,
    "keypoolsize": 101,
    "paytxfee": 0.00000000,
    "relayfee": 0.00001000,
    "errors": ""
}

In this output when you see blocks and longestchain values become the same, it means, your wallet is full synced.

you should protect your wallet (wallet.dat) which resides in ~/.komodo/wallet.dat Make several copies of this file and protect them.

Now, follow the same instructions in the 2nd machine. We are then ready to spin up our own asset chain after that.
Asset chain set up

Komodo is a fork of Zcash which in turn is a fork of Bitcoin. So, Komodo uses a lot of bitcoin codebase. It needs to nodes (Systems) to run set a blockchain. The reason for 2 nodes (systems) is that the original blockchain designs of Satoshi Nakamoto, on which Komodo is based, donot exist on a single node. Rather, it exists via a connection between two or more nodes. This is the nature of decentralization: it is on the network we rely, rather than a single authority.

Before going forward we need to check that we are able to ping both machines from one another.

Let’s spin up our Dragon chain on node 1. Before then, we will stop Komodo daemon using below commands.

~/komodo/src/komodo-cli stop

Let’s create our own asset chain using below command on node1.

./komodod -ac_name=NexaCore -ac_supply=1000000 -addnode=<IP address of the second node> &

    ac_name — Name of the chain
    ac_supply — Total supply of on the chain (Pre mint coins)
    -addnode — Add IP address of the 2nd node

You can use more available parameters to get more configuration. After running this command you get output something like this.

>>>>>>>>>> NexaCore: p2p.8096 rpc.8097 magic.c89a5b16 3365559062 1000000 coins

In this case, the p2p port is 8096. You need to make sure that this port will be open on machines.

Setup 2nd node

Now on the second node, stop the Komodo daemon and run the command below. We need to give it the IP address of the first node . We are giving a few extra parameters here -gen -genproclimit=1 to start mining as soon as it connects to 1st node.

./komodod -ac_name=NexaCore -ac_supply=1000000 -addnode=<IP address of the first node> -gen -genproclimit=1 &

Once the second node connects it will automatically mines blocks.

On a Komodo-based blockchain, all of the pre-mined coins are mined in the first block. Therefore, whichever machine executes the mining command will receive the entirety of the blockchain supply.

You can sell these coins to your customers, using either our native DEX, BarterDEX or a third party exchange.

To get the information about the asset chain you run this command.

./komodo-cli -ac_name=NexaCore getwalletinfo

To get the balance,

./komodo-cli -ac_name=NexaCore getbalance

or to know about more APIs and RPC calls you can run this command.

./komodo-cli -ac_name=NexaCore help

Now you have your asset chain and NexaCore tokens the you can list it on exchanges. (Of course you need to come with the application and sell it to customers first). BarterDex is one of the decentralize exchanges built by the Komodo team. You can list ERC20 and other bitcoin base cryptocurrencies on this exchange.
Cryptocondition Smart contract (Based on UTXO model)

Komodo introduced it’s own UTXO (Unspent transaction outputs) based smart contracts called Cryptoconditions. These contract are different from ethereum or Eos Turing complete smart contracts which runs on a virtual machine and uses GAS model. Cryptoconditions do not take gas for their execution.

Programmable UTXO

As Komodo is a bitcoin-protocol based platform, it uses UTXO model as compared to Ethereum’s address base model. So, Cryptocondition contracts works on UTXO rather than lock the balance of whole address. To understand this better, you can think UTXOs as bills on your wallet. Let’s say you have a bill of 2$, 5$ and 10$ in your wallet. Using Cryptocondition you can lock on a particular bill (fox example — 5$ bill) and other bills will be untouched. This makes UTXOs programmable.

Benefits of Cryptocondition over Ethereum smart contracts

    The main benefit of Cryptocondition is that it doesn’t take any GAS or currency to execute.
    These Cryptocondition contracts are hardcoded into Komodo blockchains all the asset chain automatically get useful smart contracts. This can work as a smart contract library for asset chains.
    You can use either C or C++ or any compiled language to code these smart contracts.
    UTXO base model provides more security and control management over the asset.
    CryptoConditions allows zero-confirmation micro-payments. Also, these zero-confirmation micro-payments are secured by Komodo’s delayed Proof of Work security mechanism. The payments are fully peer-to-peer and are considered confirmed as soon as they enter the mempool.

In the world of Decentralized apps, asset chains can enable a lot of use cases and technologies such as atomic swap, which helps in interoperability of blockchains and value transfer between multiple chains.

Komodo is building a blockchain platform with leading edge technology and hopes to power a whole new generation blockchain applications. The ecosystem needs to grow as compared to ethereum and other blockchains, but build something valuable always takes time.

In Conclusion

Any business or individual with long-term blockchain application use cases should look into Komodo’s asset chain platform.

If you have any problems checkout the official documentation of Komodo platform or leave a question on this post. If you’ve built on the Komodo platform, drop a link to your project in the comments. I’d love to check it out.

Thanks to William Wickey for help editing.
# Get (transparent) wallet and blockchain info
./komodo-cli -ac_name=NexaCore getinfo


# Get (transparent) wallet information
./komodo-cli -ac_name=NexaCore getwalletinfo


# Get mining information
./komodo-cli -ac_name=NexaCore getmininginfo


# Generate a new Z/Private address
./komodo-cli -ac_name=NexaCore z_getnewaddress


# To backup the private key of a z address
./komodo-cli -ac_name=NexaCore z_exportkey "zaddr"

# Get z balance (hidden funds don't show in transparent commands)
./komodo-cli -ac_name=NexaCore z_gettotalbalance

# To send mined coins to a z address
./komodo-cli -ac_name=NexaCore z_shieldcoinbase "fromaddress" "tozaddress" ( fee ) ( limit )

# Example 1:
./komodo-cli -ac_name=NexaCore z_shieldcoinbase "RHYDbB9ZtoqSaTvJqkCNd7EH9eLnvULSnr" "zcdYeSbZCnvcbKhUPMYWdMy9FVdgQ2y9fivhbWgCuPsbFJ5VycayAZwrgkC8dbyVZd1einoNjKBa8hsXy71B3aMNVpinvsa"

# Example 2 Combines all NexaCore in different t-addresses to 1 z-address:
./komodo-cli -ac_name=NexaCore z_shieldcoinbase "*" "zcdYeSbZCnvcbKhUPMYWdMy9FVdgQ2y9fivhbWgCuPsbFJ5VycayAZwrgkC8dbyVZd1einoNjKBa8hsXy71B3aMNVpinvsa"

# To send a transaction from your z address to another z address
./komodo-cli -ac_name=NexaCore z_sendmany "fromaddress" [{"address":... ,"amount":...},...] ( minconf ) ( fee )

# Example:
komodo-cli -ac_name=NexaCore z_sendmany "zcdYeSbZCnvcbKhUPMYWdMy9FVdgQ2y9fivhbWgCuPsbFJ5VycayAZwrgkC8dbyVZd1einoNjKBa8hsXy71B3aMNVpinvsa" '[{"address": "zcVHHtp5vTFDASaMoWXGYnPYq7n6xqwtYDFmN4F9UX4T88MscMJY9wQgyAMWpM4ttNXDyQHcFDGgegs3CBDQ9KNWvUXaaUA" ,"amount": 5.9999}]'
