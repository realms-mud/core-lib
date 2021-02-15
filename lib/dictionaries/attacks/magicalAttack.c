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
        setDamageType("magical");
        damagesEthereal();
        addHitDictionary(({
            "cast", "gesture", "chant", "intone", "speak" }));

        addSimileDictionary(({
            "streams of blue energy", "lines of yellow sparks", "tendrils of black",
            "rivulets of turquoise streamers", "shocks of silver light",
            "ribbons of crimson energy", "spirals of green light", }));

        addMissMessage("##AttackerName## ##HitDictionary## arcane syllables but "
            "##Infinitive::produce## nothing except nonsense.");

        addHitMessage("##AttackerName## ##HitDictionary## at ##TargetName##"
            " and ##Infinitive::slam## ##TargetSubjective## with "
            "##SimileDictionary##.", "1-150");
    }
}
