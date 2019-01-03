//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave string DefaultStart = "/room/city/central_park.c";

private string name = "";
private string shortDescription = "";
private string longDescription = "";
private string messageIn = "";
private string messageOut = "";
private string magicalMessageIn = "";
private string magicalMessageOut = "";
private string messageHome = "";
private string messageClone = "";
private int gender;
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

/////////////////////////////////////////////////////////////////////////////
private nosave mapping genderPronouns = ([
    1: ([ 
        "name": "male",
        "nominative": "he",
        "genitive": "his",
        "dative": "him",
        "reflexive": "himself"
    ]),
    2: ([
        "name": "female",
        "nominative": "she",
        "genitive": "her",
        "dative": "her",
        "reflexive": "herself"
    ]),
    0: ([
        "name": "neuter",
        "nominative": "it",
        "genitive": "its",
        "dative": "it",
        "reflexive": "itself"
    ])
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
        gender = persistence->extractSaveData("gender", data);
        age = persistence->extractSaveData("age", data);
        ghost = persistence->extractSaveData("ghost", data);
        title = persistence->extractSaveData("title", data);
        pretitle = persistence->extractSaveData("pretitle", data);
        invisibility = persistence->extractSaveData("invisible", data);
        whenCreated = persistence->extractSaveData("whenCreated", data);
        LastLogin = persistence->extractSaveData("LastLogin", data);
        location = persistence->extractSaveData("location", data);
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
    ret["gender"] = gender;
    ret["age"] = age;
    ret["ghost"] = ghost;
    ret["title"] = title;
    ret["pretitle"] = pretitle;
    ret["invisible"] = invisibility;

    ret["location"] = environment() ? "/" + object_name(environment()) :
        DefaultStart;

    return ret;
}
