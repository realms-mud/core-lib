//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/core.c";
#include "henchman-names.h"

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
        "concubine", "magic user", "artisan", "sage", "noble", "scholar", 
        "scion of dhuras", "phaedra", "engineer", "architect", "blacksmith", 
        "carpenter", "stonemason", "armorer", "weaponsmith", "banker", "innkeeper",
        "foreman", "retailer", "administrator", "scientist", "farmer",
        "arcane craftsman", "miner", "trader", "priest", "monk", "druid",
        "entertainer" }), data) > -1;
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
public nomask string getName(string gender)
{
    return (gender == "female") ? femaleNames[random(sizeof(femaleNames))] :
        maleNames[random(sizeof(maleNames))];
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getFamilyName()
{
    return familyNames[random(sizeof(familyNames))];
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getRandomHenchman(string type, string rating, int cost,
    int duration)
{
    mapping ret = ([]);

    if(isValidHenchmanType(type) &&
       (member(({ "apprentice", "journeyman", "master" }), rating) > -1))
    {
        string gender = (random(100) >= 50) ? "female": "male";

        ret = ([
            "name": getName(gender),
            "house": getFamilyName(),
            "gender": gender,
            "type": type,
            "traits": ({ sprintf("/lib/instances/traits/domains/%s-%s.c",
                rating, regreplace(type, " ", "-", 1)) }),
            "cost": cost,
            "duration": duration,
            "persona": "swordsman",
            "level": 5,
            "activity": "idle"
        ]);
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
    string baseline, int maxModifier, mapping skills, int isRemote)
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

    if (isRemote && (benefitType == "duration"))
    {
        ret -= 25.0;
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
                ret = "\u231b";
                break;
            }
            case "materials":
            {
                ret = "\u267b";
                break;
            }
            case "structure":
            {
                ret = "\u265c";
                break;
            }
            case "units":
            {
                ret = "\u2658";
                break;
            }
            case "combat":
            {
                ret = "\u2020";
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

    string *descriptorList = sort_array(m_indices(data), (: $1 > $2 :));
    foreach(string key in descriptorList)
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
public nomask mapping getBenefits(object user, object henchman, string type,
    string location)
{
    mapping ret = ([]);

    string baseline = getBenefitLevel(henchman, type);
    int maxModifier = getModifier("maximum modifier", baseline);
    mapping skills = getSkillsForProfession(henchman, type);

    ret["duration"] = getBenefit("duration", type, baseline, maxModifier, 
        skills, location != henchman->location());
    ret["materials"] = getBenefit("materials", type, baseline, maxModifier,
        skills, location != henchman->location());
    ret["structure"] = getBenefit("structure", type, baseline, maxModifier,
        skills, location != henchman->location());
    ret["units"] = getBenefit("units", type, baseline, maxModifier,
        skills, location != henchman->location());
    ret["combat"] = getBenefit("combat", type, baseline, maxModifier,
        skills, location != henchman->location());

    ret["description"] = displayDescription(user, ret);
    ret["level"] = baseline;
    ret["skills"] = skills + ([]);
    ret["traits"] = henchman->Traits();

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string domainModifierDisplay(string description, 
    int value, string colorConfiguration, int isReductive)
{
    string color = "heading";
    string modifierMessage = sprintf("This person has no effect to the %s "
        "on this project.", description);

    if (value)
    {
        color = (value > 0) ? "positive value" : "negative value";
        if (isReductive)
        {
            modifierMessage = (value < 0) ?
                "This person increases the %s by %d%% on this project." :
                "This person reduces the %s by %d%% on this project.";
        }
        else
        {
            modifierMessage = (value > 0) ?
                "This person increases the %s by %d%% on this project." :
                "This person reduces the %s by %d%% on this project.";
        }
        modifierMessage = sprintf(modifierMessage, description, abs(value));
    }

    return configuration->decorate(modifierMessage,
        color, "player domains", colorConfiguration) + "\n";
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getHenchmanDetails(object user, object henchman, 
    string type, string name, string location)
{
    string ret = "";
    mapping benefits = getBenefits(user, henchman, type, location);

    string colorConfiguration = user->colorConfiguration();
    string charset = user->charsetConfiguration();

    ret = configuration->decorate(sprintf("    %-6s: ", "Name"),
            "heading", "player domains", colorConfiguration) +
        configuration->decorate(name,
            "value", "player domains", colorConfiguration) + "\n" +
        configuration->decorate(sprintf("    %-6s: ", "Traits"),
            "heading", "player domains", colorConfiguration) +
        configuration->decorate(generateTitle(implode(
                henchman->TraitNames(), ", ")),
            "value", "player domains", colorConfiguration) + "\n";
    
    if (member(benefits, "skills"))
    {
        ret += configuration->decorate(sprintf("    %-6s:\n", "Skills"),
            "heading", "player domains", colorConfiguration);

        string *skillList = sort_array(m_indices(benefits["skills"]), (: $1 > $2 :));
        foreach(string skill in skillList)
        {
            int value = benefits["skills"][skill];
            string description = skill;
            if (description == "primary")
            {
                description = ProfessionSkills[type]["primary"];
            }
            ret += configuration->decorate("        " + 
                    generateTitle(description) + ": ",
                    "value", "player domains", colorConfiguration) +
                configuration->decorate(to_string(value) + "\n",
                    "positive value", "player domains", colorConfiguration);
        }
    }
    
    ret += configuration->decorate("Domain Modifiers - This worker will "
        "have the following project-level effects:\n",
            "heading", "player domains", colorConfiguration) +

        domainModifierDisplay("duration", benefits["duration"],
            colorConfiguration, 1) +
        domainModifierDisplay("materials used", benefits["materials"],
            colorConfiguration, 1) +
        domainModifierDisplay("structural strength", benefits["structure"],
            colorConfiguration) +
        domainModifierDisplay("units accomodated", benefits["units"],
            colorConfiguration) +
        domainModifierDisplay("combat modifiers", benefits["combat"],
            colorConfiguration) +

        configuration->decorate(
            sprintf("This person is considered a%s %s for this project.\n",
                (benefits["level"] == "low end worker") ? "" : "n",
                benefits["level"]),
            benefits["level"], "player domains", colorConfiguration);

    if (location != henchman->location())
    {
        ret += configuration->decorate(
            sprintf("The duration is increased because this person is not at "
                "%s.\n", generateTitle(location || "this location")),
            "negative value", "player domains", colorConfiguration);
    }

    return ret;
}
