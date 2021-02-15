//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("physical");
        addHitDictionary(({
            "puncture", "bite", "chew", "gnaw", "crush", "crunch", "masticate" }));

        addSimileDictionary(({
            "mashing ##TargetPossessive## ##BodyPart## soundly", "repeatedly on "
            "the ##BodyPart##", "with a ##BodyPart##-munching force" }));

        addMissMessage("##AttackerName## ##Infinitive::grind## ##AttackerPossessive##"
            " teeth obnoxiously.");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary## using ##AttackerPossessive## teeth.", "1-150");
    }
}
