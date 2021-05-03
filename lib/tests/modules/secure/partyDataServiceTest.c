//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object DataAccess;
object Database;

/////////////////////////////////////////////////////////////////////////////
mapping SetupPartyData()
{
    return ([
        "leader": "gorthaur",
        "name": "Gorty's Party",
        "members": ([
            "gorthaur": ([
                "party ID": 1,
                "type": "player",
                "experience earned": 2222,
                "best kill": "fred",
                "following": "",
            ]),
            "earl": ([
                "party ID": 1,
                "type": "player",
                "experience earned": 1111,
                "best kill": "henry",
                "following": "gorthaur",
            ]),
            "george": ([
                "party ID": 1,
                "type": "player",
                "experience earned": 1212,
                "best kill": "dwight",
                "following": "gorthaur",
            ]),
        ])
    ]);
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    Database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");

    mapping gorthaur = Database.Gorthaur();
    dataAccess.savePlayerData(gorthaur);
    
    gorthaur["name"] = "george";
    dataAccess.savePlayerData(gorthaur);

    gorthaur["name"] = "earl";
    dataAccess.savePlayerData(gorthaur);

    destruct(dataAccess);

    ignoreList += ({ "SetupPartyData" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    DataAccess = 
        clone_object("/lib/modules/secure/dataServices/partyDataService.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(DataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void LoadPartyDataReturnsCorrectPartyInformation()
{
    ExpectEq(([]), DataAccess.loadPartyData("gorthaur"));

    mapping saveData = SetupPartyData();
    ExpectTrue(DataAccess.savePartyData(saveData));

    saveData["ID"] = 1;
    ExpectEq(saveData, DataAccess.loadPartyData("gorthaur"));
}

/////////////////////////////////////////////////////////////////////////////
void LoadPartyListReturnsCorrectPlayersInParties()
{
    mapping saveData = SetupPartyData();
    ExpectTrue(DataAccess.savePartyData(saveData));

    ExpectEq(([ "gorthaur": 1, "earl": 1, "george": 1 ]), 
        DataAccess.loadPartyList());
}

/////////////////////////////////////////////////////////////////////////////
void RemovePartyMemberRemovesCorrectPlayer()
{
    mapping saveData = SetupPartyData();
    ExpectTrue(DataAccess.savePartyData(saveData));

    mapping result = DataAccess.loadPartyData("gorthaur");
    ExpectEq(3, sizeof(result["members"]));

    result = DataAccess.loadPartyData("earl");
    ExpectEq(3, sizeof(result["members"]));

    DataAccess.removePartyMember(1, "earl");

    ExpectEq((["gorthaur":1, "george" : 1]),
        DataAccess.loadPartyList());

    result = DataAccess.loadPartyData("gorthaur");
    ExpectEq(2, sizeof(result["members"]));

    result = DataAccess.loadPartyData("earl");
    ExpectEq(([]), result);
}

/////////////////////////////////////////////////////////////////////////////
void DeletePartyRemovesMembersAndDeletesParty()
{
    mapping saveData = SetupPartyData();
    ExpectTrue(DataAccess.savePartyData(saveData));

    ExpectEq((["gorthaur":1, "earl" : 1, "george" : 1]),
        DataAccess.loadPartyList());

    DataAccess.deleteParty(1);
    
    ExpectEq(([]), DataAccess.loadPartyList());
    ExpectEq(([]), DataAccess.loadPartyData("gorthaur"));
}
