//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("earth");
        addHitDictionary(({
            "blast", "crush", "pummel", "concuss", "flatten", "beat", "slam",
            "bash", "smash", "pound", "cudgel" }));

        addSimileDictionary(({
            "upside ##TargetPossessive## ##BodyPart##", "with an earth-shaking "
            "rumble", "with a head-splitting roar" }));

        addMissMessage("##AttackerName## ##Infinitive::gesticulate## wildly but "
            "##Infinitive::produce## little more than street theater.");

        addHitMessage("##AttackerName## ##Infinitive::summon## the powers of earth"
            " and ##HitDictionary## ##TargetName## ##SimileDictionary##.", "1-150");
    }
}



