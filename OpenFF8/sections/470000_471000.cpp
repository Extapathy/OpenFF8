// mov eax,dword ptr ds:[1CD2CA8]
// push eax
// push 0
// call <ff8_en.sub_41E972>
// add esp,8
// ret 



// mov eax,dword ptr ds:[1CD2CA8]
// push eax
// call <ff8_en.sub_>
// pop ecx
// ret 
__declspec(naked) void nakedTest() {
    __asm {
        mov eax,dword ptr ds:[0x1CD2CA8]
        push eax
        call nakedTest
        pop ecx
        ret 
    }
}


// jmp af3dn.5BAAAC80
// test eax,eax
// jne ff8_en.470242
// mov al,byte ptr ds:[1CDBFE2]
// test al,al
// jne ff8_en.470242
// mov eax,dword ptr ds:[1CDC73C]
// add eax,88F
// mov dword ptr ds:[1CDC73C],eax
// mov eax,FFFE0000
// test dword ptr ds:[1CDC73C],eax
// je ff8_en.470201
// mov ecx,dword ptr ds:[<SG_GAME_TIME>]
// inc ecx
// mov dword ptr ds:[<SG_GAME_TIME>],ecx
// mov edx,dword ptr ds:[1CDC73C]
// and edx,FFFF
// mov dword ptr ds:[1CDC73C],edx
// mov ecx,dword ptr ds:[1CDBFDC]
// add ecx,88F
// mov dword ptr ds:[1CDBFDC],ecx
// mov ecx,dword ptr ds:[1CDBFDC]
// test eax,ecx
// je ff8_en.470242
// mov eax,dword ptr ds:[<SG_COUNTDOWN>]
// test eax,eax
// je ff8_en.470242
// mov edx,dword ptr ds:[<SG_COUNTDOWN>]
// dec edx
// mov dword ptr ds:[<SG_COUNTDOWN>],edx
// mov eax,dword ptr ds:[1CDBFDC]
// and eax,FFFF
// mov dword ptr ds:[1CDBFDC],eax
// mov word ptr ds:[1CD2EFA],1
// ret 



// push ebp
// push esi
// push edi
// mov ax,word ptr ds:[1CE0758]
// mov cx,word ptr ds:[<fieldID>]
// mov dx,word ptr ds:[1CE4880]
// sub ax,2
// mov ebp,dword ptr ds:[<entity_other>]
// neg ax
// sbb eax,eax
// mov word ptr ds:[<SG_CURRENT_FIELD>],cx
// add eax,2
// mov word ptr ds:[<SG_PREV_FIELD>],dx
// mov word ptr ds:[<SG_CURRENT_MODULE>],ax
// mov ecx,ff8_en.1CFE9A4
// xor edx,edx
// mov edi,3
// xor eax,eax
// add ecx,2
// mov al,byte ptr ds:[edx+1CE4772]
// mov esi,eax
// shl eax,4
// add eax,esi
// lea eax,dword ptr ds:[eax+eax*8]
// mov esi,dword ptr ss:[ebp+eax*4+190]
// lea eax,dword ptr ss:[ebp+eax*4]
// sar esi,C
// mov word ptr ds:[ecx-8],si
// mov esi,dword ptr ds:[eax+194]
// sar esi,C
// mov word ptr ds:[ecx-2],si
// mov si,word ptr ds:[eax+1FA]
// mov word ptr ds:[ecx+4],si
// mov al,byte ptr ds:[eax+241]
// mov byte ptr ds:[edx+1CFE9B0],al
// inc edx
// dec edi
// jne ff8_en.470299
// mov cl,byte ptr ds:[1CD2FB8]
// mov dl,byte ptr ds:[1CDC748]
// pop edi
// pop esi
// mov byte ptr ds:[1CFE9B3],cl
// mov byte ptr ds:[1CFE9B4],dl
// pop ebp
// ret 



// push edi
// xor eax,eax
// mov ecx,4E9
// mov edi,<ff8_en.save_game>
// push eax
// push 4
// rep stosd dword ptr es:[edi],eax
// call <ff8_en.PlayMovie>
// add esp,8
// call <ff8_en.Movie_SetFrameLimiter>
// pop edi
// ret 



// sub esp,10
// push esi
// call ff8_en.55ABB0
// call <ff8_en.Menu_FilesPathConcenate>
// call <ff8_en.MenuLoad_PackCode>
// call <ff8_en.MenuLoad_IconVibrate>
// call <ff8_en.MenuLoad_Vibrate>
// call ff8_en.497F20
// call ff8_en.4A1AD0
// call ff8_en.4A1980
// mov esi,dword ptr ss:[esp+18]
// lea eax,dword ptr ss:[esp+4]
// push esi
// push eax
// mov dword ptr ss:[esp+14],0
// mov dword ptr ss:[esp+10],0
// mov dword ptr ss:[esp+C],0
// mov dword ptr ss:[esp+18],3F800000
// call <ff8_en.FFSetBGMaterial>
// push esi
// push 1
// push 1
// push 1
// call <ff8_en.FFClearViewport>
// add esp,18
// pop esi
// add esp,10
// ret 



// sub esp,2C
// push esi
// call <ff8_en.IsWindowActive>
// mov esi,dword ptr ss:[esp+34]
// lea eax,dword ptr ss:[esp+4]
// push esi
// push eax
// mov dword ptr ss:[esp+14],0
// mov dword ptr ss:[esp+10],0
// mov dword ptr ss:[esp+C],0
// mov dword ptr ss:[esp+18],3F800000
// call <ff8_en.FFSetBGMaterial>
// push esi
// push 1
// push 1
// push 1
// call <ff8_en.FFClearViewport>
// add esp,18
// xor eax,eax
// mov ecx,dword ptr ds:[209A798]
// cmp ecx,eax
// jne ff8_en.470436
// lea ecx,dword ptr ss:[esp+14]
// push esi
// push ecx
// mov dword ptr ss:[esp+24],ff8_en.52D970
// mov dword ptr ss:[esp+28],ff8_en.52DB90
// mov dword ptr ss:[esp+2C],<ff8_en.FFIntroModule>
// mov dword ptr ss:[esp+30],eax
// mov dword ptr ss:[esp+34],eax
// call <ff8_en.FFSwitchModule>
// add esp,8
// pop esi
// add esp,2C
// ret 
// call ff8_en.55A620
// pop esi
// add esp,2C
// ret 



// push ebx
// xor ebx,ebx
// push esi
// push edi
// mov byte ptr ds:[1CDBFE2],bl
// mov word ptr ds:[<battle_phase>],bx
// push ebx
// call <ff8_en.nullsub_3>
// call ff8_en.56BAD0
// call <ff8_en.nullsub_19>
// call ff8_en.472A50
// mov edi,<ff8_en.Paths_2>
// or ecx,FFFFFFFF
// xor eax,eax
// repne scasb al,byte ptr es:[edi]
// not ecx
// sub edi,ecx
// mov eax,ecx
// mov esi,edi
// mov edi,<ff8_en.FileNamePointer>
// shr ecx,2
// rep movsd dword ptr es:[edi],dword ptr ds:[esi]
// mov ecx,eax
// xor eax,eax
// and ecx,3
// rep movsb byte ptr es:[edi],byte ptr ds:[esi]
// mov edi,<ff8_en.aWm2field_tbl>
// or ecx,FFFFFFFF
// repne scasb al,byte ptr es:[edi]
// not ecx
// sub edi,ecx
// mov esi,edi
// mov edx,ecx
// mov edi,<ff8_en.FileNamePointer>
// or ecx,FFFFFFFF
// repne scasb al,byte ptr es:[edi]
// mov ecx,edx
// dec edi
// shr ecx,2
// rep movsd dword ptr es:[edi],dword ptr ds:[esi]
// mov eax,dword ptr ds:[B6D068]
// mov ecx,edx
// add eax,FFFFF940
// and ecx,3
// push eax
// push <ff8_en.FileNamePointer>
// rep movsb byte ptr es:[edi],byte ptr ds:[esi]
// call <ff8_en.SmPcRead>
// push 6000
// push ff8_en.1CD2FC4
// call ff8_en.49ACD0
// add esp,14
// call ff8_en.4974B0
// mov word ptr ds:[<_StateGlobal>],1
// mov word ptr ds:[1CE0758],bx
// pop edi
// mov byte ptr ds:[1CE4903],bl
// mov word ptr ds:[1CE4958],bx
// mov byte ptr ds:[<globalFieldNextModuleID>],bl
// mov byte ptr ds:[1CE4902],bl
// pop esi
// mov word ptr ds:[1CDBFE8],49
// pop ebx
// ret 



// sub esp,1C
// xor eax,eax
// lea ecx,dword ptr ss:[esp]
// mov dword ptr ss:[esp+14],eax
// mov dword ptr ss:[esp+18],eax
// mov eax,dword ptr ss:[esp+20]
// mov dword ptr ss:[esp+8],<ff8_en.FFMenuInitSystem>
// push eax
// push ecx
// mov dword ptr ss:[esp+14],<ff8_en.FFMenuExitSystem>
// mov dword ptr ss:[esp+18],<ff8_en.FFMainMenuModule>
// call <ff8_en.FFSwitchModule>
// add esp,24
// ret 



// mov eax,dword ptr ds:[1CD2EC8]
// test eax,eax
// je ff8_en.470595
// mov al,FF
// push 1
// mov word ptr ds:[<fieldID>],4A
// mov byte ptr ds:[<SG_PARTY_FIELD1>],0
// mov byte ptr ds:[<SG_PARTY_FIELD2>],al
// mov byte ptr ds:[<SG_PARTY_FIELD3>],al
// mov byte ptr ds:[1CFE993],al
// call <ff8_en.sub_52CA90>
// add esp,4
// ret 
// mov ax,word ptr ds:[<SG_CURRENT_MODULE>]
// mov word ptr ds:[<_StateGlobal>],ax
// cmp word ptr ds:[<_StateGlobal>],0
// jne ff8_en.4705B4
// mov word ptr ds:[<_StateGlobal>],1
// mov cx,word ptr ds:[<SG_CURRENT_FIELD>]
// mov dx,word ptr ds:[<SG_PREV_FIELD>]
// mov ax,word ptr ds:[1CFE99E]
// mov word ptr ds:[<fieldID>],cx
// mov cx,word ptr ds:[1CFE9A4]
// mov word ptr ds:[1CE4880],dx
// mov dx,word ptr ds:[1CFE9AA]
// mov word ptr ds:[1CE4764],ax
// movzx ax,byte ptr ds:[1CFE9B0]
// mov word ptr ds:[1CE4766],cx
// mov cl,byte ptr ds:[1CFE9B3]
// mov word ptr ds:[1CE476C],dx
// mov dl,byte ptr ds:[1CFE9B4]
// push 0
// mov word ptr ds:[1CE476E],ax
// mov byte ptr ds:[1CD2FB8],cl
// mov byte ptr ds:[1CDC748],dl
// call <ff8_en.sub_52CA90>
// pop ecx
// ret 



// sub esp,1C
// mov eax,dword ptr ss:[esp+20]
// push esi
// lea ecx,dword ptr ss:[esp+4]
// xor esi,esi
// push eax
// push ecx
// mov dword ptr ss:[esp+14],<ff8_en.FFModuleHandlerInitSystem>
// mov dword ptr ss:[esp+18],<ff8_en.FFModuleHandlerExitSystem>
// mov dword ptr ss:[esp+1C],<ff8_en.FFModuleHandler>
// mov dword ptr ss:[esp+20],esi
// mov dword ptr ss:[esp+24],esi
// call <ff8_en.FFSwitchModule>
// add esp,8
// mov dword ptr ds:[1CD2EE0],esi
// mov dword ptr ds:[1CD2EE4],esi
// mov dword ptr ds:[1CD2EE8],esi
// mov dword ptr ds:[1CD2EEC],esi
// mov dword ptr ds:[1CD2EF0],esi
// pop esi
// add esp,1C
// ret 



// mov eax,dword ptr ss:[esp+4]
// mov dword ptr ds:[eax+B88],0
// ret 



// mov eax,dword ptr ss:[esp+4]
// mov dword ptr ds:[eax+B88],1
// ret 



// sub esp,24
// push ebx
// push ebp
// push esi
// xor ebx,ebx
// push edi
// cmp word ptr ds:[1CE0758],bx
// mov ebp,dword ptr ss:[esp+38]
// jne ff8_en.47077F
// call af3dn.5BABF270
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+CC]
// cmp ecx,eax
// je ff8_en.470785
// push 1
// call <ff8_en.nullsub_20>
// mov edi,<ff8_en.Paths_2>
// or ecx,FFFFFFFF
// xor eax,eax
// repne scasb al,byte ptr es:[edi]
// not ecx
// sub edi,ecx
// mov edx,ecx
// mov esi,edi
// mov edi,<ff8_en.FileNamePointer>
// shr ecx,2
// rep movsd dword ptr es:[edi],dword ptr ds:[esi]
// mov ecx,edx
// and ecx,3
// rep movsb byte ptr es:[edi],byte ptr ds:[esi]
// mov edi,<ff8_en.aWm2field_tbl>
// or ecx,FFFFFFFF
// repne scasb al,byte ptr es:[edi]
// not ecx
// sub edi,ecx
// mov esi,edi
// mov edx,ecx
// mov edi,<ff8_en.FileNamePointer>
// or ecx,FFFFFFFF
// repne scasb al,byte ptr es:[edi]
// mov ecx,edx
// dec edi
// shr ecx,2
// rep movsd dword ptr es:[edi],dword ptr ds:[esi]
// mov eax,dword ptr ds:[B6D068]
// mov ecx,edx
// add eax,FFFFF940
// and ecx,3
// push eax
// push <ff8_en.FileNamePointer>
// rep movsb byte ptr es:[edi],byte ptr ds:[esi]
// call <ff8_en.SmPcRead>
// lea ecx,dword ptr ss:[esp+24]
// push ebp
// push ecx
// mov dword ptr ss:[esp+34],ff8_en.52DC00
// mov dword ptr ss:[esp+38],ff8_en.52DCA0
// mov dword ptr ss:[esp+3C],ff8_en.52DCF0
// mov dword ptr ss:[esp+40],ebx
// mov dword ptr ss:[esp+44],ebx
// call <ff8_en.FFSwitchModule>
// add esp,14
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// cmp byte ptr ds:[<globalFieldNextModuleID>],4
// jne ff8_en.4707C2
// call <ff8_en.xorEAX_0>
// push ebx
// call ff8_en.49F520
// call <ff8_en.sub_49E8E0>
// push 3
// call <ff8_en.__initp_misc_winxfltr>
// mov dword ptr ss:[esp+28],ff8_en.52D970
// mov dword ptr ss:[esp+2C],ff8_en.52DB90
// mov dword ptr ss:[esp+30],<ff8_en.FFIntroModule>
// jmp ff8_en.470EEF
// movsx eax,word ptr ds:[<_StateGlobal>]
// dec eax
// cmp eax,A
// ja ff8_en.470F05
// jmp dword ptr ds:[eax*4+<&InvokeFieldModule>]
// lea eax,dword ptr ss:[esp+18]
// push ebp
// push eax
// mov dword ptr ss:[esp+28],<ff8_en.FFFieldInitSystem>
// mov dword ptr ss:[esp+2C],<ff8_en.FFFieldExitSystem>
// mov dword ptr ss:[esp+30],<ff8_en.FFFieldModule>
// mov dword ptr ss:[esp+34],ebx
// mov dword ptr ss:[esp+38],ebx
// call <ff8_en.FFSwitchModule>
// add esp,8
// pop edi
// pop esi
// pop ebp
// pop ebx
// add esp,24
// ret 
// mov eax,dword ptr ds:[1CD2EE4]
// sub eax,ebx
// je ff8_en.470923
// dec eax
// je ff8_en.470966
// dec eax
// jne ff8_en.470F05
// cmp dword ptr ds:[1CD2ECC],ebx
// je ff8_en.47085D
// mov word ptr ds:[<MenuState>],bx
// mov byte ptr ds:[<globalFieldNextModuleID>],4
// mov word ptr ds:[1CE476C],7FFF
// call <ff8_en.xorEAX_0>
// pop edi
// pop esi
// mov dword ptr ds:[1CD2EE4],ebx
// pop ebp
// pop ebx
// add esp,24
// ret 
// mov word ptr ds:[1CE0758],2
// movsx eax,byte ptr ds:[<moduleIndex>]
// dec eax
// je ff8_en.4708AC
// sub eax,2
// je ff8_en.470895
// sub eax,2
// jne ff8_en.470915
// mov word ptr ds:[<_StateGlobal>],6
// pop edi
// pop esi
// mov dword ptr ds:[1CD2EE4],ebx
// pop ebp
// pop ebx
// add esp,24
// ret 
// mov word ptr ds:[<_StateGlobal>],3
// pop edi
// pop esi
// mov dword ptr ds:[1CD2EE4],ebx
// pop ebp
// pop ebx
// add esp,24
// ret 
// mov ecx,dword ptr ds:[B6D068]
// lea eax,dword ptr ds:[ecx-6C0]
// movsx ecx,byte ptr ds:[2036B4E]
// mov dword ptr ds:[1CD2EDC],eax
// lea edx,dword ptr ds:[ecx+ecx*2]
// mov cx,word ptr ds:[eax+edx*8+6]
// mov word ptr ds:[<fieldID>],cx
// lea eax,dword ptr ds:[eax+edx*8]
// mov dx,word ptr ds:[eax]
// mov word ptr ds:[1CE4764],dx
// mov cx,word ptr ds:[eax+2]
// mov word ptr ds:[1CE4766],cx
// mov dx,word ptr ds:[eax+4]
// mov word ptr ds:[1CE476C],dx
// movzx ax,byte ptr ds:[eax+8]
// mov word ptr ds:[1CE476E],ax
// mov word ptr ds:[<_StateGlobal>],1
// push ebx
// push FFFFFFFF
// call ff8_en.46B450
// add esp,8
// pop edi
// pop esi
// mov dword ptr ds:[1CD2EE4],ebx
// pop ebp
// pop ebx
// add esp,24
// ret 
// movsx eax,word ptr ds:[1CE0758]
// cmp eax,6
// ja ff8_en.47095C
// jmp dword ptr ds:[eax*4+470F3C]
// call ff8_en.522200
// mov byte ptr ds:[<moduleIndex>],bl
// jmp ff8_en.47095C
// mov byte ptr ds:[<moduleIndex>],2
// jmp ff8_en.47095C
// mov byte ptr ds:[<moduleIndex>],4
// jmp ff8_en.47095C
// mov byte ptr ds:[<moduleIndex>],6
// mov dword ptr ds:[1CD2EE4],1
// lea ecx,dword ptr ss:[esp+18]
// push ebp
// push ecx
// mov dword ptr ss:[esp+28],<ff8_en.FFWorldInitSystem>
// mov dword ptr ss:[esp+2C],<ff8_en.FFWorldExitSystem>
// mov dword ptr ss:[esp+30],<ff8_en.FFWorldModule>
// mov dword ptr ss:[esp+34],ebx
// mov dword ptr ss:[esp+38],ebx
// call <ff8_en.FFSwitchModule>
// add esp,8
// mov dword ptr ds:[1CD2EE4],2
// pop edi
// pop esi
// pop ebp
// pop ebx
// add esp,24
// ret 
// mov eax,dword ptr ds:[1CD2EE8]
// sub eax,ebx
// je ff8_en.4709D6
// dec eax
// jne ff8_en.470F05
// mov word ptr ds:[1CE0758],3
// mov word ptr ds:[<_StateGlobal>],1
// pop edi
// pop esi
// mov dword ptr ds:[1CD2EE8],ebx
// pop ebp
// pop ebx
// add esp,24
// ret 
// lea edx,dword ptr ss:[esp+18]
// push ebp
// push edx
// mov dword ptr ss:[esp+28],<ff8_en.FFBattleInitSystem>
// mov dword ptr ss:[esp+2C],<ff8_en.FFBattleExitSystem>
// mov dword ptr ss:[esp+30],af3dn.5BAA7DC0
// mov dword ptr ss:[esp+34],ebx
// mov dword ptr ss:[esp+38],ebx
// call <ff8_en.FFSwitchModule>
// add esp,8
// mov dword ptr ds:[1CD2EE8],1
// pop edi
// pop esi
// pop ebp
// pop ebx
// add esp,24
// ret 
// mov eax,dword ptr ds:[1CD2EE0]
// sub eax,ebx
// je ff8_en.470ADC
// dec eax
// jne ff8_en.470F05
// mov al,byte ptr ds:[<battle_result>]
// mov dword ptr ds:[1CD2EE0],ebx
// cmp al,5
// jne ff8_en.470A58
// pop edi
// pop esi
// mov word ptr ds:[<MenuState>],bx
// pop ebp
// mov byte ptr ds:[<globalFieldNextModuleID>],4
// mov word ptr ds:[1CE476C],7FFF
// pop ebx
// add esp,24
// ret 
// cmp al,1
// jne ff8_en.470A67
// test byte ptr ds:[esi+B7],2
// jne ff8_en.470A9D
// jmp ff8_en.470A74
// cmp al,3
// jne ff8_en.470A9D
// test byte ptr ds:[esi+B7],1
// jne ff8_en.470A95
// mov word ptr ds:[<fieldID>],4B
// mov word ptr ds:[1CE0758],bx
// mov word ptr ds:[<_StateGlobal>],1
// pop edi
// pop esi
// pop ebp
// pop ebx
// add esp,24
// ret 
// mov eax,dword ptr ds:[esi+68]
// and al,BF
// mov dword ptr ds:[esi+68],eax
// mov eax,1
// cmp word ptr ds:[1CE0758],ax
// mov word ptr ds:[1CE0758],3
// mov word ptr ds:[<_StateGlobal>],B
// jne ff8_en.470ACB
// pop edi
// pop esi
// pop ebp
// mov word ptr ds:[1CD2ED4],ax
// pop ebx
// add esp,24
// ret 
// pop edi
// pop esi
// pop ebp
// mov word ptr ds:[1CD2ED4],2
// pop ebx
// add esp,24
// ret 
// mov esi,1
// cmp word ptr ds:[1CE0758],si
// jne ff8_en.470AFF
// mov ax,word ptr ds:[<MenuState>]
// mov ecx,dword ptr ds:[1CDC6EC]
// mov word ptr ds:[<EncounterID>],ax
// push ecx
// jmp ff8_en.470B37
// mov edx,dword ptr ds:[B80878]
// mov ax,word ptr ds:[B8087C]
// mov dword ptr ss:[esp+10],edx
// xor ecx,ecx
// movzx dx,byte ptr ds:[2036B4E]
// mov ch,byte ptr ds:[2036B4F]
// mov word ptr ss:[esp+14],ax
// or ecx,edx
// lea eax,dword ptr ss:[esp+10]
// mov word ptr ds:[<EncounterID>],cx
// mov byte ptr ss:[esp+14],5
// push eax
// call <ff8_en.Battle_KeepMusicAfterBattle>
// add esp,4
// mov dword ptr ss:[esp+20],<ff8_en.FFBattleTransitionInitSystem>
// mov dword ptr ss:[esp+24],<ff8_en.FFBattleTransitionExitSystem>
// mov dword ptr ss:[esp+28],<ff8_en.FFBattleTransitionModule>
// push ebx
// mov dword ptr ss:[esp+30],ebx
// call ff8_en.559520
// lea ecx,dword ptr ss:[esp+1C]
// push ebp
// push ecx
// mov dword ptr ss:[esp+3C],ebx
// call <ff8_en.FFSwitchModule>
// add esp,C
// mov dword ptr ds:[1CD2EE0],esi
// pop edi
// pop esi
// pop ebp
// pop ebx
// add esp,24
// ret 
// mov eax,dword ptr ds:[1CD2EEC]
// cmp eax,4
// ja ff8_en.470F05
// jmp dword ptr ds:[eax*4+470F58]
// xor eax,eax
// mov dword ptr ds:[1CD2ED0],eax
// jmp ff8_en.470BA9
// mov eax,dword ptr ds:[1CD2ED0]
// cmp eax,3
// jge ff8_en.470C18
// cmp byte ptr ds:[eax+1CFF6E4],FF
// je ff8_en.470C06
// mov dword ptr ds:[1CD2EEC],2
// lea edx,dword ptr ss:[esp+18]
// push ebp
// push edx
// mov dword ptr ss:[esp+28],<ff8_en.FFMenuInitSystem>
// mov dword ptr ss:[esp+2C],<ff8_en.FFMenuExitSystem>
// mov dword ptr ss:[esp+30],<ff8_en.FFMenuModule>
// mov dword ptr ss:[esp+34],ebx
// mov dword ptr ss:[esp+38],ebx
// call <ff8_en.FFSwitchModule>
// mov ecx,dword ptr ds:[1CD2ED0]
// xor eax,eax
// add esp,8
// mov dword ptr ds:[B87798],ebx
// mov al,byte ptr ds:[ecx+1CFF6E4]
// add eax,5
// mov dword ptr ds:[1D2BB98],eax
// pop edi
// pop esi
// pop ebp
// mov dword ptr ds:[1CD2EEC],3
// pop ebx
// add esp,24
// ret 
// pop edi
// pop esi
// pop ebp
// mov dword ptr ds:[1CD2EEC],4
// pop ebx
// add esp,24
// ret 
// mov eax,dword ptr ds:[1CD2ED0]
// pop edi
// inc eax
// pop esi
// pop ebp
// mov dword ptr ds:[1CD2ED0],eax
// mov dword ptr ds:[1CD2EEC],1
// pop ebx
// add esp,24
// ret 
// mov dx,word ptr ds:[1CD2ED4]
// mov dword ptr ds:[1CD2EEC],ebx
// mov word ptr ds:[<_StateGlobal>],dx
// pop edi
// pop esi
// pop ebp
// pop ebx
// add esp,24
// ret 
// mov eax,dword ptr ds:[1CD2EF0]
// sub eax,ebx
// je ff8_en.470E22
// dec eax
// je ff8_en.470D97
// dec eax
// jne ff8_en.470F05
// mov eax,dword ptr ds:[1D2BB9C]
// mov esi,1
// mov dword ptr ds:[1CD2ED8],eax
// cmp word ptr ds:[1CE0758],si
// jne ff8_en.470CD9
// test al,1
// je ff8_en.470CC7
// call ff8_en.52D110
// mov ax,word ptr ds:[<_StateGlobal>]
// sub ax,6
// neg ax
// sbb eax,eax
// and al,FC
// add eax,A
// mov word ptr ds:[1CE0758],ax
// mov eax,dword ptr ds:[1CD2ED8]
// mov word ptr ds:[<_StateGlobal>],si
// jmp ff8_en.470CEB
// mov word ptr ds:[1CE0758],6
// mov word ptr ds:[<_StateGlobal>],si
// jmp ff8_en.470CEB
// mov word ptr ds:[1CE0758],6
// mov word ptr ds:[<_StateGlobal>],2
// test al,4
// jne ff8_en.470CFD
// pop edi
// pop esi
// mov dword ptr ds:[1CD2EF0],ebx
// pop ebp
// pop ebx
// add esp,24
// ret 
// mov cx,word ptr ds:[<_StateGlobal>]
// mov word ptr ds:[1CE0758],cx
// mov word ptr ds:[<_StateGlobal>],3
// sar eax,10
// mov word ptr ds:[<EncounterID>],ax
// cmp word ptr ds:[<_StateGlobal>],si
// jne ff8_en.470D2E
// mov edx,dword ptr ds:[1CDC6EC]
// jmp ff8_en.470D4C
// mov cx,word ptr ds:[B8087C]
// mov eax,dword ptr ds:[B80878]
// mov word ptr ss:[esp+14],cx
// mov dword ptr ss:[esp+10],eax
// mov byte ptr ss:[esp+14],5
// lea edx,dword ptr ss:[esp+10]
// push edx
// call <ff8_en.Battle_KeepMusicAfterBattle>
// add esp,4
// mov dword ptr ss:[esp+20],<ff8_en.FFBattleTransitionInitSystem>
// mov dword ptr ss:[esp+24],<ff8_en.FFBattleTransitionExitSystem>
// mov dword ptr ss:[esp+28],<ff8_en.FFBattleTransitionModule>
// push ebx
// mov dword ptr ss:[esp+30],ebx
// mov dword ptr ss:[esp+34],ebx
// call ff8_en.559520
// lea eax,dword ptr ss:[esp+1C]
// push ebp
// push eax
// call <ff8_en.FFSwitchModule>
// add esp,C
// mov dword ptr ds:[1CD2EE0],esi
// pop edi
// pop esi
// pop ebp
// pop ebx
// add esp,24
// ret 
// call <ff8_en.sub_470250>
// cmp word ptr ds:[1CE0758],1
// jne ff8_en.470DC3
// movsx ecx,word ptr ds:[<MenuState>]
// xor edx,edx
// mov dword ptr ds:[1D2BB98],ecx
// mov dl,byte ptr ds:[1CE490B]
// mov dword ptr ds:[B87798],edx
// jmp ff8_en.470DE2
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// xor eax,eax
// mov dword ptr ds:[1D2BB98],80000000
// mov al,byte ptr ds:[ecx+D1]
// or al,1
// mov dword ptr ds:[B87798],eax
// lea edx,dword ptr ss:[esp+18]
// push ebp
// push edx
// mov dword ptr ss:[esp+28],<ff8_en.FFMenuInitSystem>
// mov dword ptr ss:[esp+2C],<ff8_en.FFMenuExitSystem>
// mov dword ptr ss:[esp+30],<ff8_en.FFMenuModule>
// mov dword ptr ss:[esp+34],ebx
// mov dword ptr ss:[esp+38],ebx
// call <ff8_en.FFSwitchModule>
// add esp,8
// mov dword ptr ds:[1CD2EF0],2
// pop edi
// pop esi
// pop ebp
// pop ebx
// add esp,24
// ret 
// pop edi
// pop esi
// pop ebp
// mov dword ptr ds:[1CD2EF0],1
// pop ebx
// add esp,24
// ret 
// mov eax,dword ptr ds:[1CE4900]
// and eax,FF
// push eax
// call <ff8_en.nullsub_20>
// mov al,byte ptr ds:[1CE4900]
// add esp,4
// cmp al,1
// jne ff8_en.470F05
// mov edi,<ff8_en.Paths_2>
// or ecx,FFFFFFFF
// xor eax,eax
// repne scasb al,byte ptr es:[edi]
// not ecx
// sub edi,ecx
// mov edx,ecx
// mov esi,edi
// mov edi,<ff8_en.FileNamePointer>
// shr ecx,2
// rep movsd dword ptr es:[edi],dword ptr ds:[esi]
// mov ecx,edx
// and ecx,3
// rep movsb byte ptr es:[edi],byte ptr ds:[esi]
// mov edi,<ff8_en.aWm2field_tbl>
// or ecx,FFFFFFFF
// repne scasb al,byte ptr es:[edi]
// not ecx
// sub edi,ecx
// mov esi,edi
// mov edx,ecx
// mov edi,<ff8_en.FileNamePointer>
// or ecx,FFFFFFFF
// repne scasb al,byte ptr es:[edi]
// mov ecx,edx
// dec edi
// shr ecx,2
// rep movsd dword ptr es:[edi],dword ptr ds:[esi]
// mov eax,dword ptr ds:[B6D068]
// mov ecx,edx
// add eax,FFFFF940
// and ecx,3
// push eax
// push <ff8_en.FileNamePointer>
// rep movsb byte ptr es:[edi],byte ptr ds:[esi]
// call <ff8_en.SmPcRead>
// mov cx,word ptr ds:[<MenuState>]
// mov word ptr ds:[<fieldID>],cx
// mov word ptr ds:[1CE0758],bx
// mov word ptr ds:[<_StateGlobal>],1
// mov dword ptr ss:[esp+28],ff8_en.52DC00
// mov dword ptr ss:[esp+2C],ff8_en.52DCA0
// mov dword ptr ss:[esp+30],ff8_en.52DCF0
// lea edx,dword ptr ss:[esp+20]
// push ebp
// push edx
// mov dword ptr ss:[esp+3C],ebx
// mov dword ptr ss:[esp+40],ebx
// call <ff8_en.FFSwitchModule>
// add esp,10
// pop edi
// pop esi
// pop ebp
// pop ebx
// add esp,24
// ret 



// call ff8_en.4A28C0
// jmp <ff8_en.unknown_libname_4>



// mov eax,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ss:[esp+C]
// mov edx,eax
// mov cl,byte ptr ds:[esi]
// test cl,cl
// je ff8_en.470F9C
// mov byte ptr ds:[edx],cl
// mov cl,byte ptr ds:[esi+1]
// inc edx
// inc esi
// test cl,cl
// jne ff8_en.470F91
// mov byte ptr ds:[edx],0
// pop esi



// mov ecx,dword ptr ss:[esp+4]
// xor eax,eax
// cmp byte ptr ds:[ecx],0
// je ff8_en.470FC4
// mov dl,byte ptr ds:[eax+ecx+1]
// inc eax
// test dl,dl
// jne ff8_en.470FBB
// ret 



// mov eax,dword ptr ss:[esp+4]
// xor ecx,ecx
// cmp byte ptr ds:[eax],0
// je ff8_en.470FE4
// mov dl,byte ptr ds:[ecx+eax+1]
// inc ecx
// test dl,dl
// jne ff8_en.470FDB
// push esi
// mov esi,dword ptr ss:[esp+C]
// lea edx,dword ptr ds:[ecx+eax]
// mov cl,byte ptr ds:[esi]
// test cl,cl
// je ff8_en.470FFD
// mov byte ptr ds:[edx],cl
// mov cl,byte ptr ds:[esi+1]
// inc edx
// inc esi
// test cl,cl
// jne ff8_en.470FF2
// mov byte ptr ds:[edx],0
// pop esi
// ret 