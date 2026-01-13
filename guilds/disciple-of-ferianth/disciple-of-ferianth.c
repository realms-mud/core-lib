//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("Disciple of Ferianth");
    addPreferredSkillType("magic");

    addRank("acolyte", ([
        "name": "acolyte",
        "title": "the Disciple of Ferianth",
        "pretitle": "Acolyte",
        "next rank": "flame keeper",
        "delay for next promotion": 1200
    ]));

    addRank("flame keeper", ([
        "name": "flame keeper",
        "title": "the Disciple of Ferianth",
        "pretitle": "Flame Keeper",
        "previous rank": "acolyte",
        "next rank": "ardent",
        "delay for next promotion": 3600
    ]));

    addRank("ardent", ([
        "name": "ardent",
        "title": "the Disciple of Ferianth",
        "pretitle": "Ardent",
        "previous rank": "flame keeper",
        "next rank": "high priest",
        "delay for next promotion": 7200
    ]));

    addRank("high priest", ([
        "name": "high priest",
        "title": "the Disciple of Ferianth",
        "pretitle": "High Priest",
        "previous rank": "ardent",
        "next rank": "exarch",
        "delay for next promotion": 7200
    ]));

    addRank("exarch", ([
        "name": "exarch",
        "title": ", Exarch of Ferianth",
        "pretitle": "Exarch",
        "previous rank": "high priest"
    ]));

    setDefaultRank("acolyte");

    // Resources - balanced caster with healing capability
    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "3 every level",
        "begin at level": 1
    ]));

    addCriteria("spell points", ([
        "type": "modifier",
        "apply": "5 every level",
        "begin at level": 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply": "3 every level",
        "begin at level": 1
    ]));

    addCriteria("attribute points", ([
        "type": "attribute points",
        "apply": "1 every 5 levels"
    ]));

    addCriteria("skill points", ([
        "type": "skill points",
        "apply": "5 every level"
    ]));

    // Research points
    addCriteria("initial research points", ([
        "type": "research points",
        "apply": "5 at level 1"
    ]));

    addCriteria("research points", ([
        "type": "research points",
        "apply": "1 every level"
    ]));

    addCriteria("supplemental research points", ([
        "type": "research points",
        "apply": "2 every 5 levels"
    ]));

    // Inferno - primary offensive fire magic
    addCriteria("inferno", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/disciple-of-ferianth/inferno.c"
    ]));

    // Purifying Flames - healing and cleansing magic
    addCriteria("purifying flames", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/disciple-of-ferianth/purifying-flames.c"
    ]));

    // Ember Arts - utility and buff spells
    addCriteria("ember arts", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/disciple-of-ferianth/ember-arts.c"
    ]));

    // Wildfire - DoT and spread damage
    addCriteria("wildfire", ([
        "type": "research tree",
        "apply": "at level 3",
        "research tree": "/guilds/disciple-of-ferianth/wildfire.c"
    ]));

    // Flame Conduit - transformation into fire-being (like nightmare persona)
    addCriteria("flame conduit", ([
        "type": "research tree",
        "apply": "at level 5",
        "research tree": "/guilds/disciple-of-ferianth/flame-conduit.c"
    ]));

    // Ashen Retribution - defensive/counter abilities (Flame Keeper rank)
    addCriteria("ashen retribution", ([
        "type": "research tree",
        "apply": "at rank flame keeper",
        "research tree": "/guilds/disciple-of-ferianth/ashen-retribution.c"
    ]));

    // Sacred Pyre - divine rituals and prayers (Ardent rank)
    addCriteria("sacred pyre", ([
        "type": "research tree",
        "apply": "at rank ardent",
        "research tree": "/guilds/disciple-of-ferianth/sacred-pyre.c"
    ]));

    // Divine Conflagration - high priest abilities (High Priest rank)
    addCriteria("divine conflagration", ([
        "type": "research tree",
        "apply": "at rank high priest",
        "research tree": "/guilds/disciple-of-ferianth/divine-conflagration.c"
    ]));

    // Ferianth's Grace - ultimate divine powers (Exarch rank)
    addCriteria("ferianths grace", ([
        "type": "research tree",
        "apply": "at rank exarch",
        "research tree": "/guilds/disciple-of-ferianth/ferianths-grace.c"
    ]));
}
