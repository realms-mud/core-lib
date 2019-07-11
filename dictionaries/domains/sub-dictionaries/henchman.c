//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/core.c";

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidActivity(string location, string activity)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidHenchmanType(string data)
{
    return member(({ "aegis", "diplomat", "senechal", "advisor", "soldier",
        "concubine", "mage", "artisan", "sage", "noble", "scholar",
        "engineer", "architect", "craftsman", "banker", "innkeeper",
        "retailer", "manager", "scientist", "arcane craftsman" }), data) > -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidHenchman(mapping data)
{
    int ret = mappingp(data);
    if (ret && member(data, "skills"))
    {
        ret &&= mappingp(data["skills"]) && sizeof(data["skills"]);
        if (ret)
        {
            object skillsDictionary = 
                load_object("/lib/dictionaries/skillsDictionary.c");

            foreach(string skill in m_indices(data["skills"]))
            {
                ret &&= skillsDictionary->isValidSkill(skill);
            }
        }
    }

    if (ret && member(data, "traits"))
    {
        ret &&= pointerp(data["traits"]) && sizeof(data["traits"]);
        if (ret)
        {
            object traitsDictionary = 
                load_object("/lib/dictionaries/traitsDictionary.c");

            foreach(string trait in data["traits"])
            {
                ret &&= traitsDictionary->validTrait(trait);
            }
        }
    }

    return ret && mappingp(data) && member(data, "name") &&
        member(data, "type") && isValidHenchmanType(data["type"]) &&
        member(data, "persona") && member(data, "level") &&
        member(data, "activity");
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getHenchmanFromData(mapping data, object user)
{
    object ret = 0;
    
    if (isValidHenchman(data))
    {
        ret = clone_object("/lib/realizations/henchman.c");
        ret->setHenchmanData(data, user);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getBenefits(object henchman, string type)
{
    return "";
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getBenefitLevel(object henchman, string type)
{
    string traits = implode(henchman->Traits(type), "");
    string santizedType = regreplace(type, " .*", "", 1);
    string ret = "low end worker";

    if (sizeof(regexp(({ traits }), "master-" + santizedType)))
    {
        ret = "elite worker";
    }
    else if (sizeof(regexp(({ traits }), "journeyman-" + santizedType)))
    {
        ret = "average worker";
    }
    return ret;
}
