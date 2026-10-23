-- Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
-- See the accompanying LICENSE file for details.
DROP PROCEDURE IF EXISTS saveTemporaryTraits;
##
CREATE PROCEDURE saveTemporaryTraits (p_playerid int, p_traits varchar(512))
BEGIN
    declare temporaryTraitId int;

    select id into temporaryTraitId
    from temporaryTraits where playerid = p_playerid;

    if temporaryTraitId is not null then
        update temporaryTraits set traitList = p_traits
        where id = temporaryTraitId;
    else
        insert into temporaryTraits (playerid, traitList)
        values (p_playerid, p_traits);
    end if;
END;
