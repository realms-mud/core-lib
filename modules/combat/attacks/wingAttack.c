//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("physical");
        addHitDictionary(({
            "bash", "slam", "slap", "pummel", "crush", "pound", "buffet", "smack",
            "assault" }));

        addSimileDictionary(({
            "smashing ##TargetPossessive## ##BodyPart## soundly", "repeatedly in "
            "the ##BodyPart##", "with a ##BodyPart##-whipping force" }));

        addMissMessage("##AttackerName## ##Infinitive::flap## ##AttackerPossessive##"
            " wings wildly!");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary## with ##AttackerPossessive## wings.", "1-150");
    }
}
