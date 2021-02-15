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
            "bash", "slam", "slap", "pummel", "crush", "pound", "whip", "smack",
            "assault" }));

        addSimileDictionary(({
            "whacking ##TargetPossessive## ##BodyPart## soundly", "repeatedly in "
            "the ##BodyPart##", "with a ##BodyPart##-shattering force" }));

        addMissMessage("##AttackerName## ##Infinitive::thrash## ##AttackerPossessive##"
            " tail at nothing.");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary## with ##AttackerPossessive## tail.", "1-150");
    }
}
