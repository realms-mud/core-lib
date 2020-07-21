//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave string DefaultStart = StartLocation();

private string name = "";
private string shortDescription = "";
private string longDescription = "";
private string messageIn = "";
private string messageOut = "";
private string magicalMessageIn = "";
private string magicalMessageOut = "";
private string messageHome = "";
private string messageClone = "";
private string gender = "neuter";
private int age;
private string *aliases = ({});
private int ghost = 0;
private string title;
private string pretitle;
private int invisibility;
private mapping properties = ([]);
private string whenCreated;
private string LastLogin;
private string location = DefaultStart;
private int isGuest = 0;

/////////////////////////////////////////////////////////////////////////////
private nosave mapping genderPronouns = ([
    1: "male",
    2: "female",
    0: "neuter",
    "male": ([ 
        "name": "male",
        "index": 1,
        "nominative": "he",
        "genitive": "his",
        "dative": "him",
        "reflexive": "himself"
    ]),
    "female": ([
        "name": "female",
        "index": 2,
        "nominative": "she",
        "genitive": "her",
        "dative": "her",
        "reflexive": "herself"
    ]),
    "neuter": ([
        "name": "neuter",
        "index": 0,
        "nominative": "it",
        "genitive": "its",
        "dative": "it",
        "reflexive": "itself"
    ]),
]);

/////////////////////////////////////////////////////////////////////////////
static nomask void loadMaterialAttributes(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        name = persistence->extractSaveData("name", data);
        shortDescription = persistence->extractSaveData("shortDescription", data);
        longDescription = persistence->extractSaveData("longDescription", data);
        messageIn = persistence->extractSaveData("messageIn", data);
        messageOut = persistence->extractSaveData("messageOut", data);
        magicalMessageIn = persistence->extractSaveData("magicalMessageIn", data);
        magicalMessageOut = persistence->extractSaveData("magicalMessageOut", data);
        messageHome = persistence->extractSaveData("messageHome", data);
        messageClone = persistence->extractSaveData("messageClone", data);
        gender = genderPronouns[persistence->extractSaveData("gender", data)];
        age = persistence->extractSaveData("age", data);
        ghost = persistence->extractSaveData("ghost", data);
        title = persistence->extractSaveData("title", data);
        pretitle = persistence->extractSaveData("pretitle", data);
        invisibility = persistence->extractSaveData("invisible", data);
        whenCreated = persistence->extractSaveData("whenCreated", data);
        LastLogin = persistence->extractSaveData("LastLogin", data);
        location = persistence->extractSaveData("location", data);
        isGuest = persistence->extractSaveData("is guest", data);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendMaterialAttributes()
{
    mapping ret = ([]);

    ret["name"] = name;
    ret["shortDescription"] = shortDescription;
    ret["longDescription"] = longDescription;
    ret["messageIn"] = messageIn;
    ret["messageOut"] = messageOut;
    ret["magicalMessageIn"] = magicalMessageIn;
    ret["magicalMessageOut"] = magicalMessageOut;
    ret["messageHome"] = messageHome;
    ret["messageClone"] = messageClone;
    ret["gender"] = genderPronouns[gender]["index"];
    ret["age"] = age;
    ret["ghost"] = ghost;
    ret["title"] = title;
    ret["pretitle"] = pretitle;
    ret["invisible"] = invisibility;
    ret["is guest"] = isGuest;

    ret["location"] = environment() && environment()->environmentName() ? 
        environment()->environmentName() : DefaultStart;

    return ret;
}
