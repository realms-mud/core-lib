//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/core.c";

private mapping Modifiers = ([
    "duration": ([
        "baseline": 10,
        "tiers": ({ "average worker", "elite worker" }),
        "penalty": 7,
    ]),
    "materials": ([
        "baseline": 10,
        "tiers": ({ "average worker", "elite worker" }),
        "penalty": 7,
    ]),
    "structure": ([
        "baseline": 20,
        "tiers": ({ "average worker", "elite worker" }),
        "penalty": 7,
    ]),
    "units": ([
        "baseline": 25,
        "tiers": ({ "elite worker" }),
        "penalty": 0,
    ]),
    "combat": ([
        "baseline": 25,
        "tiers": ({ "elite worker" }),
        "penalty": 0
    ]),
]);

private mapping ProfessionSkills = ([
    "arcane craftsman": ([
        "primary": "engineering",
        "others": ([
            "mathematics": ({ "duration", "materials" }),
            "physics": ({ "materials", "structure" }),
            "spellcraft": ({ "structure", "units", "combat" })
        ])
    ]),
    "architect": ([
        "primary": "engineering",
        "others": ([
            "mathematics":({ "duration", "materials", "units" }),
            "physics": ({ "materials", "structure", "combat" }),
        ])
    ]),
    "blacksmith": ([
        "primary": "blacksmithing",
        "others": ([
            "metal crafting": ({ "duration", "materials", "structure" }),
        ])
    ]),
    "carpenter": ([
        "primary": "carpentry",
        "others": ([
            "wood crafting": ({ "duration", "materials", "structure" }),
        ])
    ]),
    "engineer": ([
        "primary": "engineering",
        "others": ([
            "mathematics":({ "duration", "materials" }),
            "physics": ({ "materials", "structure" }),
        ])
    ]),
    "foreman": ([
        "primary": "engineering",
        "others": ([
            "mathematics":({ "duration", "materials" }),
            "physics": ({ "materials", "structure" }),
        ])
    ]),
    "stonemason": ([
        "primary": "stonemasonry",
        "others": ([
            "physics":({ "materials", "structure" }),
        ]),
    ]),
]);

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
public nomask string getBenefitLevel(object henchman, string type)
{
    string traits = implode(henchman->Traits(type), "");
    string santizedType = regreplace(type, " ", "-", 1);
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

/////////////////////////////////////////////////////////////////////////////
private nomask int getModifier(string type, string tier)
{
    mapping modifiers = ([
        "elite worker":([
            "maximum modifier": 50,
            "base": 10,
        ]),
        "average worker":([
            "maximum modifier": 10,
            "base": 0,
        ]),
        "low end worker":([
            "maximum modifier": -1,
            "base": -5,
        ]),
    ]);

    return modifiers[tier][type];
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getSkillsForProfession(object henchman,
    string profession)
{
    mapping skills = ([
        "primary": henchman->getSkill(
            ProfessionSkills[profession]["primary"])
    ]);

    foreach(string skill in 
        m_indices(ProfessionSkills[profession]["others"]))
    {
        skills[skill] = henchman->getSkill(skill);
    }

    return skills;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getBenefit(string benefitType, string profession, 
    string baseline, int maxModifier, mapping skills)
{
    float ret = 0.0;

    if (member(Modifiers, benefitType))
    {
        ret = getModifier("base", baseline) * 1.0;

        if (member(Modifiers[benefitType]["tiers"], baseline) > -1)
        {
            if (skills["primary"] >= Modifiers[benefitType]["baseline"])
            {
                ret += (skills["primary"] - Modifiers[benefitType]["baseline"]) / 5.0;

                if (ret > maxModifier)
                {
                    ret = maxModifier * 1.0;
                }
            }
        }
        else if (Modifiers[benefitType]["penalty"])
        {
            ret = skills["primary"] - Modifiers[benefitType]["penalty"];
        }

        string *skillList = m_indices(skills) - ({ "primary" });
        foreach(string skill in skillList)
        {
            if ((member(ProfessionSkills[profession]["others"][skill],
                benefitType) > -1) && 
                (skills[skill] > (Modifiers[benefitType]["baseline"] - 5)))
            {
                ret += (skills[skill] / 5.0);
            }
        }
    }
    return to_int(ret);
}


/////////////////////////////////////////////////////////////////////////////
private nomask string getDecorator(string type, string charset)
{
    string ret = "";

    if (charset == "unicode")
    {
        switch (type)
        {
            case "duration":
            {
                ret = "\xe2\x8c\x9b";
                break;
            }
            case "materials":
            {
                ret = "\xe2\x99\xbb";
                break;
            }
            case "structure":
            {
                ret = "\xe2\x99\x9c";
                break;
            }
            case "units":
            {
                ret = "\xe2\x99\x98";
                break;
            }
            case "combat":
            {
                ret = "\xe2\x80\xa0";
                break;
            }
        }
    }
    else
    {
        ret = capitalize(type[0..0]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayField(string type, int value, 
    string colorConfiguration, string charset)
{
    string ret = "";

    if (value)
    {
        int isPositive = (value > 0);
        string valueColor = isPositive ? "positive value" : "negative value";

        ret = configuration->decorate(
                sprintf("%s: ", getDecorator(type, charset)),
                "selected", "player domains", colorConfiguration) +
            configuration->decorate(sprintf("%s%d%%", isPositive ? "+" : "",
                value),
                valueColor, "player domains", colorConfiguration);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayDescription(object user, mapping data)
{
    string colorConfiguration = user->colorConfiguration();
    string charset = user->charsetConfiguration();

    string *descriptions = ({});
    foreach(string key in m_indices(data))
    {
        descriptions += ({
            displayField(key, data[key], colorConfiguration, charset)
            });
    }
    descriptions -= ({ "" });

    if (!sizeof(descriptions))
    {
        descriptions += ({
            configuration->decorate("No bonuses or penalties",
                "heading", "player domains", colorConfiguration) });
    }

    return implode(descriptions, ", ");
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBenefits(object user, object henchman, string type)
{
    mapping ret = ([]);

    string baseline = getBenefitLevel(henchman, type);
    int maxModifier = getModifier("maximum modifier", baseline);
    mapping skills = getSkillsForProfession(henchman, type);

    ret["duration"] = getBenefit("duration", type, baseline, maxModifier, skills);
    ret["materials"] = getBenefit("materials", type, baseline, maxModifier, skills);
    ret["structure"] = getBenefit("structure", type, baseline, maxModifier, skills);
    ret["units"] = getBenefit("units", type, baseline, maxModifier, skills);
    ret["combat"] = getBenefit("combat", type, baseline, maxModifier, skills);

    ret["description"] = displayDescription(user, ret);

    return ret;
}
