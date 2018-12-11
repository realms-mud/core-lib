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
            "sting", "slap", "slash", "whip" }));

        addSimileDictionary(({
            "slicing ##TargetPossessive## ##BodyPart## soundly", "repeatedly in "
            "the ##BodyPart##", "with a ##BodyPart##-welting force" }));

        addMissMessage("##AttackerName## ##Infinitive::make## that strange"
            " raspberry sound with ##AttackerPossessive## tongue.");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary## with ##AttackerPossessive## tongue.", "1-150");
    }
}
