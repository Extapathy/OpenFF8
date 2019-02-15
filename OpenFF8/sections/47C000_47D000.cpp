// push esi
// mov esi,dword ptr ss:[esp+C]
// push edi
// movsx eax,word ptr ds:[esi+21E]
// cmp eax,6
// mov byte ptr ds:[esi+258],0
// ja ff8_en.47CA6C
// mov ecx,3
// jmp dword ptr ds:[eax*4+47CA70]
// mov eax,dword ptr ds:[esi+190]
// mov edx,dword ptr ds:[esi+194]
// mov dword ptr ds:[esi+19C],eax
// mov eax,dword ptr ds:[esi+198]
// mov byte ptr ds:[esi+23E],0
// mov dword ptr ds:[esi+1A0],edx
// mov dword ptr ds:[esi+1A4],eax
// mov word ptr ds:[esi+1DA],0
// mov word ptr ds:[1CDC73A],1F
// mov word ptr ds:[1CDC738],3E
// mov word ptr ds:[esi+21E],cx
// cmp word ptr ds:[esi+21A],1
// jne ff8_en.47C35D
// xor eax,eax
// mov edi,dword ptr ss:[esp+C]
// mov ax,word ptr ds:[1CE475C]
// push 1
// push 1
// lea eax,dword ptr ds:[eax+eax*2]
// shl eax,2
// mov byte ptr ds:[eax+1CDC322],cl
// mov byte ptr ds:[eax+1CDC022],cl
// mov cl,byte ptr ds:[esi+252]
// push ecx
// push edi
// call ff8_en.478270
// movsx edi,di
// mov eax,edi
// push 0
// shl eax,4
// add eax,edi
// push 1
// push 1
// lea edx,dword ptr ds:[eax+eax*8]
// mov eax,dword ptr ds:[<entity_other>]
// lea ecx,dword ptr ds:[eax+edx*4]
// push ecx
// jmp ff8_en.47C3AB
// xor eax,eax
// mov edi,dword ptr ss:[esp+C]
// mov ax,word ptr ds:[1CE475C]
// mov cl,5
// push FFFFFFFF
// push 1
// lea eax,dword ptr ds:[eax+eax*2]
// shl eax,2
// mov byte ptr ds:[eax+1CDC322],cl
// mov byte ptr ds:[eax+1CDC022],cl
// mov dl,byte ptr ds:[esi+254]
// push edx
// push edi
// call ff8_en.478270
// movsx edi,di
// mov ecx,dword ptr ds:[<entity_other>]
// mov eax,edi
// shl eax,4
// add eax,edi
// push 0
// push FFFFFFFF
// push 1
// lea eax,dword ptr ds:[eax+eax*8]
// lea edx,dword ptr ds:[ecx+eax*4]
// push edx
// call ff8_en.478870
// add esp,20
// call ff8_en.478680
// mov eax,dword ptr ds:[edi*4+1DCB340]
// movsx edx,word ptr ds:[esi+1DA]
// mov cx,word ptr ds:[eax+C]
// push edx
// shr cx,4
// mov edx,dword ptr ds:[esi+19C]
// lea eax,dword ptr ds:[ecx-2]
// mov ecx,dword ptr ds:[esi+1A8]
// mov word ptr ds:[esi+1D8],ax
// movsx eax,ax
// push eax
// push ecx
// push edx
// call ff8_en.475C60
// movsx ecx,word ptr ds:[esi+1D8]
// mov edx,dword ptr ds:[esi+1AC]
// mov dword ptr ds:[esi+190],eax
// movsx eax,word ptr ds:[esi+1DA]
// push eax
// mov eax,dword ptr ds:[esi+1A0]
// push ecx
// push edx
// push eax
// call ff8_en.475C60
// movsx ecx,word ptr ds:[esi+1DA]
// movsx edx,word ptr ds:[esi+1D8]
// mov dword ptr ds:[esi+194],eax
// mov eax,dword ptr ds:[esi+1B0]
// push ecx
// mov ecx,dword ptr ds:[esi+1A4]
// push edx
// push eax
// push ecx
// call ff8_en.475C60
// mov dword ptr ds:[esi+198],eax
// mov dl,byte ptr ds:[1CE475C]
// mov cl,byte ptr ds:[1CE495C]
// push 1
// sub dl,cl
// push ff8_en.1CDC318
// and edx,3F
// push edx
// push 2
// call ff8_en.478430
// mov al,byte ptr ds:[1CE475C]
// mov cl,byte ptr ds:[1CE495A]
// add esp,40
// sub al,cl
// and eax,3F
// push 1
// push ff8_en.1CDC018
// push eax
// push 1
// call ff8_en.478430
// xor eax,eax
// mov cl,byte ptr ds:[esi+241]
// mov ax,word ptr ds:[1CE475C]
// add esp,10
// lea eax,dword ptr ds:[eax+eax*2]
// shl eax,2
// mov byte ptr ds:[eax+1CDC323],cl
// mov byte ptr ds:[eax+1CDC023],cl
// inc word ptr ds:[esi+1DA]
// mov ax,word ptr ds:[esi+1DA]
// cmp ax,word ptr ds:[esi+1D8]
// jl ff8_en.47CA6C
// mov eax,dword ptr ds:[esi+1C0]
// mov ecx,dword ptr ds:[esi+1A8]
// sub eax,ecx
// cdq 
// and edx,3FF
// add eax,edx
// mov edx,dword ptr ds:[esi+1AC]
// mov ecx,eax
// mov eax,dword ptr ds:[esi+1C4]
// sub eax,edx
// cdq 
// and edx,3FF
// add eax,edx
// mov edx,dword ptr ds:[esi+1B0]
// mov edi,eax
// mov eax,dword ptr ds:[esi+1C8]
// sub eax,edx
// cdq 
// and edx,3FF
// add eax,edx
// sar eax,A
// mov edx,eax
// sar edi,A
// imul edx,eax
// mov eax,edi
// imul eax,edi
// sar ecx,A
// add edx,eax
// mov eax,ecx
// imul eax,ecx
// add edx,eax
// push edx
// call ff8_en.56BEC0
// xor ecx,ecx
// add esp,4
// mov cl,byte ptr ds:[1CE490E]
// mov word ptr ds:[esi+1DA],0
// cdq 
// idiv ecx
// mov word ptr ds:[esi+21E],1
// pop edi
// mov word ptr ds:[esi+1D8],ax
// pop esi
// ret 
// mov edx,dword ptr ss:[esp+14]
// mov eax,dword ptr ss:[esp+C]
// push edx
// push eax
// call ff8_en.47BE80
// add esp,8
// pop edi
// pop esi
// ret 
// cmp word ptr ds:[esi+21A],1
// jne ff8_en.47C5CB
// xor eax,eax
// mov edi,dword ptr ss:[esp+C]
// mov ax,word ptr ds:[1CE475C]
// mov cl,5
// push 1
// push 1
// lea eax,dword ptr ds:[eax+eax*2]
// shl eax,2
// mov byte ptr ds:[eax+1CDC322],cl
// mov byte ptr ds:[eax+1CDC022],cl
// mov cl,byte ptr ds:[esi+254]
// push ecx
// push edi
// call ff8_en.478270
// movsx edi,di
// mov eax,edi
// push 0
// shl eax,4
// add eax,edi
// push 1
// push 1
// lea edx,dword ptr ds:[eax+eax*8]
// mov eax,dword ptr ds:[<entity_other>]
// lea ecx,dword ptr ds:[eax+edx*4]
// push ecx
// jmp ff8_en.47C61C
// xor eax,eax
// mov edi,dword ptr ss:[esp+C]
// mov ax,word ptr ds:[1CE475C]
// mov ecx,3
// push FFFFFFFF
// push 1
// lea eax,dword ptr ds:[eax+eax*2]
// shl eax,2
// mov byte ptr ds:[eax+1CDC322],cl
// mov byte ptr ds:[eax+1CDC022],cl
// mov dl,byte ptr ds:[esi+252]
// push edx
// push edi
// call ff8_en.478270
// movsx edi,di
// mov ecx,dword ptr ds:[<entity_other>]
// mov eax,edi
// shl eax,4
// add eax,edi
// push 0
// push FFFFFFFF
// push 1
// lea eax,dword ptr ds:[eax+eax*8]
// lea edx,dword ptr ds:[ecx+eax*4]
// push edx
// call ff8_en.478870
// add esp,20
// call ff8_en.478680
// mov eax,dword ptr ds:[edi*4+1DCB340]
// movsx edx,word ptr ds:[esi+1DA]
// mov cx,word ptr ds:[eax+C]
// push edx
// shr cx,4
// mov edx,dword ptr ds:[esi+1C0]
// lea eax,dword ptr ds:[ecx-2]
// mov ecx,dword ptr ds:[esi+1B4]
// mov word ptr ds:[esi+1D8],ax
// movsx eax,ax
// push eax
// push ecx
// push edx
// call ff8_en.475C60
// movsx ecx,word ptr ds:[esi+1D8]
// mov edx,dword ptr ds:[esi+1B8]
// mov dword ptr ds:[esi+190],eax
// movsx eax,word ptr ds:[esi+1DA]
// push eax
// mov eax,dword ptr ds:[esi+1C4]
// push ecx
// push edx
// push eax
// call ff8_en.475C60
// movsx ecx,word ptr ds:[esi+1DA]
// movsx edx,word ptr ds:[esi+1D8]
// mov dword ptr ds:[esi+194],eax
// mov eax,dword ptr ds:[esi+1BC]
// push ecx
// mov ecx,dword ptr ds:[esi+1C8]
// push edx
// push eax
// push ecx
// call ff8_en.475C60
// mov dword ptr ds:[esi+198],eax
// mov dl,byte ptr ds:[1CE475C]
// mov cl,byte ptr ds:[1CE495C]
// push 1
// sub dl,cl
// push ff8_en.1CDC318
// and edx,3F
// push edx
// push 2
// call ff8_en.478430
// mov al,byte ptr ds:[1CE475C]
// mov cl,byte ptr ds:[1CE495A]
// add esp,40
// sub al,cl
// and eax,3F
// push 1
// push ff8_en.1CDC018
// push eax
// push 1
// call ff8_en.478430
// xor eax,eax
// mov cl,byte ptr ds:[esi+241]
// mov ax,word ptr ds:[1CE475C]
// add esp,10
// lea eax,dword ptr ds:[eax+eax*2]
// shl eax,2
// mov byte ptr ds:[eax+1CDC323],cl
// mov byte ptr ds:[eax+1CDC023],cl
// inc word ptr ds:[esi+1DA]
// mov ax,word ptr ds:[esi+1DA]
// cmp ax,word ptr ds:[esi+1D8]
// jl ff8_en.47CA6C
// mov cx,word ptr ds:[esi+1FC]
// mov word ptr ds:[esi+1DA],0
// mov word ptr ds:[esi+1FA],cx
// mov word ptr ds:[esi+21E],6
// pop edi
// pop esi
// ret 
// cmp word ptr ds:[esi+21A],1
// jne ff8_en.47C7B9
// xor eax,eax
// mov edi,dword ptr ss:[esp+C]
// mov ax,word ptr ds:[1CE475C]
// mov ecx,3
// push FFFFFFFF
// push 1
// lea eax,dword ptr ds:[eax+eax*2]
// shl eax,2
// mov byte ptr ds:[eax+1CDC322],cl
// mov byte ptr ds:[eax+1CDC022],cl
// mov dl,byte ptr ds:[esi+252]
// push edx
// push edi
// call ff8_en.478270
// movsx edi,di
// mov ecx,dword ptr ds:[<entity_other>]
// mov eax,edi
// shl eax,4
// add eax,edi
// push 0
// push FFFFFFFF
// push 1
// lea eax,dword ptr ds:[eax+eax*8]
// lea edx,dword ptr ds:[ecx+eax*4]
// push edx
// jmp ff8_en.47C807
// xor eax,eax
// mov edi,dword ptr ss:[esp+C]
// mov ax,word ptr ds:[1CE475C]
// mov cl,5
// push 1
// push 1
// lea eax,dword ptr ds:[eax+eax*2]
// shl eax,2
// mov byte ptr ds:[eax+1CDC322],cl
// mov byte ptr ds:[eax+1CDC022],cl
// mov al,byte ptr ds:[esi+254]
// push eax
// push edi
// call ff8_en.478270
// movsx edi,di
// mov edx,dword ptr ds:[<entity_other>]
// mov eax,edi
// shl eax,4
// add eax,edi
// push 0
// push 1
// push 1
// lea ecx,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[edx+ecx*4]
// push eax
// call ff8_en.478870
// add esp,20
// call ff8_en.478680
// mov ecx,dword ptr ds:[edi*4+1DCB340]
// mov dx,word ptr ds:[ecx+C]
// movsx ecx,word ptr ds:[esi+1DA]
// shr dx,4
// push ecx
// mov ecx,dword ptr ds:[esi+1A8]
// lea eax,dword ptr ds:[edx-2]
// movsx edx,ax
// mov word ptr ds:[esi+1D8],ax
// mov eax,dword ptr ds:[esi+19C]
// push edx
// push eax
// push ecx
// call ff8_en.475C60
// movsx edx,word ptr ds:[esi+1DA]
// mov ecx,dword ptr ds:[esi+1A0]
// mov dword ptr ds:[esi+190],eax
// movsx eax,word ptr ds:[esi+1D8]
// push edx
// mov edx,dword ptr ds:[esi+1AC]
// push eax
// push ecx
// push edx
// call ff8_en.475C60
// movsx ecx,word ptr ds:[esi+1D8]
// mov edx,dword ptr ds:[esi+1A4]
// mov dword ptr ds:[esi+194],eax
// movsx eax,word ptr ds:[esi+1DA]
// push eax
// mov eax,dword ptr ds:[esi+1B0]
// push ecx
// push edx
// push eax
// call ff8_en.475C60
// mov dword ptr ds:[esi+198],eax
// mov cl,byte ptr ds:[1CE475C]
// mov al,byte ptr ds:[1CE495C]
// push 1
// sub cl,al
// push ff8_en.1CDC318
// and ecx,3F
// push ecx
// push 2
// call ff8_en.478430
// mov dl,byte ptr ds:[1CE475C]
// mov cl,byte ptr ds:[1CE495A]
// add esp,40
// sub dl,cl
// and edx,3F
// push 1
// push ff8_en.1CDC018
// push edx
// push 1
// call ff8_en.478430
// xor eax,eax
// mov cl,byte ptr ds:[esi+241]
// mov ax,word ptr ds:[1CE475C]
// add esp,10
// lea eax,dword ptr ds:[eax+eax*2]
// shl eax,2
// mov byte ptr ds:[eax+1CDC323],cl
// mov byte ptr ds:[eax+1CDC023],cl
// inc word ptr ds:[esi+1DA]
// mov ax,word ptr ds:[esi+1DA]
// cmp ax,word ptr ds:[esi+1D8]
// jl ff8_en.47CA6C
// mov word ptr ds:[esi+1DA],0
// mov word ptr ds:[esi+21E],6
// pop edi
// pop esi
// ret 
// xor eax,eax
// mov edi,dword ptr ss:[esp+C]
// mov ax,word ptr ds:[1CE475C]
// mov word ptr ds:[1CDC73A],F
// mov word ptr ds:[1CDC738],1E
// push FFFFFFFF
// lea eax,dword ptr ds:[eax+eax*2]
// push 1
// shl eax,2
// mov byte ptr ds:[eax+1CDC322],2
// mov byte ptr ds:[eax+1CDC022],2
// mov al,byte ptr ds:[esi+24F]
// push eax
// push edi
// call ff8_en.478270
// movsx ecx,di
// mov edx,dword ptr ds:[<entity_other>]
// mov eax,ecx
// shl eax,4
// add eax,ecx
// push 0
// push FFFFFFFF
// push 1
// lea ecx,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[edx+ecx*4]
// push eax
// call ff8_en.478870
// add esp,20
// call ff8_en.478680
// cmp word ptr ds:[esi+1DA],0
// jne ff8_en.47C9E3
// mov cl,byte ptr ds:[1CE4774]
// mov al,FF
// cmp cl,al
// je ff8_en.47C9C7
// mov word ptr ds:[esi+1D8],20
// jmp ff8_en.47C9E3
// cmp byte ptr ds:[1CE4773],al
// je ff8_en.47C9DA
// mov word ptr ds:[esi+1D8],10
// jmp ff8_en.47C9E3
// mov word ptr ds:[esi+1D8],1
// mov cl,byte ptr ds:[1CE475C]
// mov al,byte ptr ds:[1CE495C]
// sub cl,al
// push 2
// and ecx,3F
// push ff8_en.1CDC318
// push ecx
// push 2
// call ff8_en.478430
// mov dl,byte ptr ds:[1CE475C]
// mov cl,byte ptr ds:[1CE495A]
// sub dl,cl
// push 2
// and edx,3F
// push ff8_en.1CDC018
// push edx
// push 1
// call ff8_en.478430
// xor eax,eax
// mov cl,byte ptr ds:[esi+241]
// mov ax,word ptr ds:[1CE475C]
// add esp,20
// lea eax,dword ptr ds:[eax+eax*2]
// shl eax,2
// mov byte ptr ds:[eax+1CDC323],cl
// mov byte ptr ds:[eax+1CDC023],cl
// inc word ptr ds:[esi+1DA]
// mov ax,word ptr ds:[esi+1DA]
// cmp ax,word ptr ds:[esi+1D8]
// mov byte ptr ds:[esi+258],1
// jl ff8_en.47CA6C
// mov word ptr ds:[esi+21E],2
// pop edi
// pop esi
// ret 



// mov al,byte ptr ds:[<globalFieldNextModuleID>]
// cmp al,1
// je ff8_en.47CC6A
// cmp al,7
// je ff8_en.47CC6A
// call ff8_en.52B3A0
// test eax,eax
// jne ff8_en.47CC6A
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov cl,byte ptr ds:[eax+CF]
// test cl,cl
// jne ff8_en.47CC6A
// cmp word ptr ds:[1CE4868],4
// je ff8_en.47CC6A
// cmp word ptr ds:[1CE4868],3
// je ff8_en.47CC6A
// cmp word ptr ds:[1CE4868],2
// je ff8_en.47CC6A
// mov al,byte ptr ds:[1CDC74C]
// cmp al,1
// je ff8_en.47CC6A
// mov cl,byte ptr ds:[1CFF6D8]
// test cl,8
// jne ff8_en.47CC6A
// mov edx,dword ptr ds:[1CF3D48]
// test cl,4
// mov eax,dword ptr ds:[edx]
// je ff8_en.47CB2A
// mov al,byte ptr ds:[eax]
// xor cx,cx
// shr al,1
// mov cl,al
// add word ptr ds:[1CDC740],cx
// jmp ff8_en.47CB35
// movzx dx,byte ptr ds:[eax]
// add word ptr ds:[1CDC740],dx
// cmp word ptr ds:[1CDC740],100
// jbe ff8_en.47CC6A
// movsx ecx,word ptr ds:[1CD8FD0]
// mov eax,ecx
// and word ptr ds:[1CDC740],FF
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+eax*8]
// movsx ecx,word ptr ds:[ecx+eax*4+1FE]
// mov eax,309E0185
// imul ecx
// sar edx,8
// mov eax,edx
// shr eax,1F
// add edx,eax
// mov al,byte ptr ds:[1CD2FB8]
// add word ptr ds:[1CDC74A],dx
// inc al
// mov byte ptr ds:[1CD2FB8],al
// jne ff8_en.47CB99
// add byte ptr ds:[1CDC748],D
// mov al,byte ptr ds:[1CDC748]
// xor ecx,ecx
// mov cl,byte ptr ds:[1CD2FB8]
// mov dl,byte ptr ds:[ecx+B80A18]
// add dl,al
// xor ax,ax
// mov al,dl
// cmp ax,word ptr ds:[1CDC74A]
// jae ff8_en.47CC6A
// mov al,byte ptr ds:[1CDBFEC]
// mov edx,dword ptr ds:[1CF3D78]
// inc al
// xor ecx,ecx
// mov cl,al
// push esi
// mov si,word ptr ds:[1CDC6E0]
// mov byte ptr ds:[<globalFieldNextModuleID>],3
// mov cl,byte ptr ds:[ecx+B80A18]
// mov byte ptr ds:[1CD2EF8],1
// mov word ptr ds:[1CDC74A],0
// mov byte ptr ds:[1CDBFEC],al
// mov eax,dword ptr ds:[edx]
// cmp cl,80
// jae ff8_en.47CC1B
// mov dx,word ptr ds:[eax]
// cmp si,dx
// je ff8_en.47CC1B
// mov ax,dx
// pop esi
// mov word ptr ds:[<MenuState>],ax
// mov word ptr ds:[1CDC6E0],ax
// ret 
// cmp cl,C0
// jae ff8_en.47CC3A
// mov dx,word ptr ds:[eax+2]
// cmp si,dx
// je ff8_en.47CC3A
// mov ax,dx
// pop esi
// mov word ptr ds:[<MenuState>],ax
// mov word ptr ds:[1CDC6E0],ax
// ret 
// cmp cl,F0
// jae ff8_en.47CC59
// mov cx,word ptr ds:[eax+4]
// cmp si,cx
// je ff8_en.47CC59
// mov ax,cx
// pop esi
// mov word ptr ds:[<MenuState>],ax
// mov word ptr ds:[1CDC6E0],ax
// ret 
// mov ax,word ptr ds:[eax+6]
// pop esi
// mov word ptr ds:[<MenuState>],ax
// mov word ptr ds:[1CDC6E0],ax
// ret



// mov ecx,dword ptr ds:[B80F9C]
// xor eax,eax
// cmp cx,FFFF
// push esi
// je ff8_en.47CCA6
// mov si,word ptr ds:[<EncounterID>]
// mov edx,ff8_en.B80F9C
// cmp si,cx
// je ff8_en.47CCA1
// mov cx,word ptr ds:[edx+2]
// add edx,2
// cmp cx,FFFF
// jne ff8_en.47CC8C
// pop esi
// ret 
// mov eax,1
// pop esi
// ret



// movsx eax,word ptr ds:[<_StateGlobal>]
// add eax,FFFFFFFD
// cmp eax,5
// ja ff8_en.47CDBE
// jmp dword ptr ds:[eax*4+47CDE4]
// mov eax,dword ptr ds:[B6D064]
// push eax
// push <ff8_en.aBtitle_ovl>
// call <ff8_en.SmPcRead>
// add esp,8
// jmp <ff8_en.Battle_HiddenDebug>
// mov eax,dword ptr ds:[1CFF83C]
// mov dword ptr ds:[1CFF840],0
// cmp eax,3
// ja ff8_en.47CDE3
// jmp dword ptr ds:[eax*4+47CDFC]
// push 0
// call <ff8_en.Set1D2B814>
// push 0
// call <ff8_en.ShowCountdownTimer>
// add esp,8
// mov dword ptr ds:[1CFF83C],1
// mov eax,dword ptr ds:[B80F9C]
// xor edx,edx
// cmp ax,FFFF
// push esi
// je ff8_en.47CD4F
// mov si,word ptr ds:[<EncounterID>]
// mov ecx,ff8_en.B80F9C
// cmp si,ax
// je ff8_en.47CD4A
// mov ax,word ptr ds:[ecx+2]
// add ecx,2
// cmp ax,FFFF
// jne ff8_en.47CD36
// jmp ff8_en.47CD4F
// mov edx,1
// push edx
// call <ff8_en.xorEAX>
// add esp,4
// mov dword ptr ds:[1CFF83C],2
// pop esi
// ret 
// mov ecx,dword ptr ds:[B6D074]
// mov eax,dword ptr ds:[B6D064]
// sub ecx,eax
// sar ecx,4
// push ecx
// push eax
// call <ff8_en.sub_47E410>
// add esp,8
// mov dword ptr ds:[1CFF83C],3
// ret 
// jmp <ff8_en.battle_related>
// mov word ptr ds:[<battle_phase>],0
// mov dword ptr ds:[1CFF840],1
// jmp ff8_en.534640
// call ff8_en.4A6680
// mov word ptr ds:[<battle_phase>],4
// mov word ptr ds:[<_StateGlobal>],64
// ret 
// mov word ptr ds:[<_StateGlobal>],4
// mov eax,dword ptr ds:[1CFF840]
// test eax,eax
// je ff8_en.47CDD9
// mov word ptr ds:[<_StateGlobal>],8
// mov dword ptr ds:[<StopBattleDword>],1
// ret



// push esi
// push edi
// xor esi,esi
// mov ecx,4D1
// xor eax,eax
// mov edi,ff8_en.1D27B00
// mov dword ptr ds:[<StopBattleDword>],esi
// mov dword ptr ds:[1CFF83C],esi
// rep stosd dword ptr es:[edi],eax
// cmp word ptr ds:[<_StateGlobal>],8
// jne ff8_en.47CE3F
// push 404E4000
// jmp ff8_en.47CE44
// push 402F0000
// push esi
// call ff8_en.4020C0
// add esp,8
// push 3F4CCCCD
// call ff8_en.460B60
// mov eax,dword ptr ds:[1A7764C]
// mov ecx,dword ptr ds:[1A77648]
// mov edx,dword ptr ds:[<width>]
// mov dword ptr ds:[1A77E78],eax
// mov eax,dword ptr ds:[<height>]
// add esp,4
// mov dword ptr ds:[1A78BD0],eax
// mov eax,dword ptr ds:[<High_resolution>]
// cmp eax,esi
// mov dword ptr ds:[1A77E7C],ecx
// mov dword ptr ds:[1A78BCC],edx
// je ff8_en.47CEB3
// xor eax,eax
// mov ecx,18
// mov edx,280
// mov dword ptr ds:[1A7764C],eax
// mov dword ptr ds:[1A77648],ecx
// mov dword ptr ds:[<width>],edx
// mov esi,1B0
// jmp ff8_en.47CED8
// mov eax,A0
// mov ecx,84
// mov edx,140
// mov dword ptr ds:[1A7764C],eax
// mov dword ptr ds:[1A77648],ecx
// mov dword ptr ds:[<width>],edx
// mov esi,D8
// push esi
// push edx
// push ecx
// push eax
// mov dword ptr ds:[<height>],esi
// call <ff8_en.SetResolution>
// add esp,10
// pop edi
// pop esi
// ret 



// push esi
// call <ff8_en.nullsub_944>
// mov esi,dword ptr ds:[1A78BD0]
// mov edx,dword ptr ds:[1A78BCC]
// mov ecx,dword ptr ds:[1A77E7C]
// mov eax,dword ptr ds:[1A77E78]
// push esi
// push edx
// push ecx
// push eax
// mov dword ptr ds:[1A7764C],eax
// mov dword ptr ds:[1A77648],ecx
// mov dword ptr ds:[<width>],edx
// mov dword ptr ds:[<height>],esi
// call <ff8_en.SetResolution>
// mov eax,dword ptr ss:[esp+18]
// add esp,10
// mov dword ptr ds:[eax+B88],1
// call <ff8_en.sub_45B580>
// call ff8_en.4647A0
// pop esi
// ret 



// mov eax,dword ptr ss:[esp+4]
// inc eax
// mov dword ptr ds:[1CFF6F4],eax
// ret



// sub esp,1C
// push ebx
// push esi
// mov esi,dword ptr ss:[esp+28]
// xor ebx,ebx
// cmp dword ptr ds:[esi+BA8],ebx
// jne ff8_en.47CF87
// push 1E0
// push 280
// push ebx
// push ebx
// call <ff8_en.SetResolution>
// add esp,10
// lea eax,dword ptr ss:[esp+8]
// push esi
// push eax
// mov dword ptr ss:[esp+18],0
// mov dword ptr ss:[esp+14],0
// mov dword ptr ss:[esp+10],0
// mov dword ptr ss:[esp+1C],3F800000
// call <ff8_en.FFSetBGMaterial>
// push esi
// push 1
// push 1
// push 1
// call <ff8_en.FFClearViewport>
// mov eax,dword ptr ds:[esi+BA8]
// add esp,18
// cmp eax,ebx
// jne ff8_en.47CFEE
// mov ecx,dword ptr ds:[<height>]
// mov edx,dword ptr ds:[<width>]
// mov eax,dword ptr ds:[1A77648]
// push ecx
// mov ecx,dword ptr ds:[1A7764C]
// push edx
// push eax
// push ecx
// call <ff8_en.SetResolution>
// add esp,10
// push esi
// push ebx
// call <ff8_en.sub_41E972>
// add esp,8
// test eax,eax
// je ff8_en.47D243
// mov edx,dword ptr ds:[1D2A284]
// push edx
// call <ff8_en.sub_416B9A>
// mov eax,dword ptr ds:[1D2A288]
// push eax
// call <ff8_en.sub_424BF9>
// call <ff8_en.sub_49B120>
// call <ff8_en.sub_499A40>
// push esi
// call <ff8_en.sub_43FBE8>
// push esi
// call <ff8_en.sub_409B42>
// push esi
// call <ff8_en.sub_409B08>
// push esi
// call <ff8_en.sub_409B25>
// add esp,18
// call <ff8_en.___setargv_2>
// mov al,byte ptr ds:[1D28DEA]
// cmp al,bl
// je ff8_en.47D0D3
// call <ff8_en.sub_4A71D0>
// test eax,eax
// je ff8_en.47D0D3
// mov dword ptr ds:[1CFF834],1
// mov dword ptr ds:[1CFF844],ebx
// mov dword ptr ds:[esi+B88],1
// call <ff8_en.sub_45B580>
// call <ff8_en.UpdateTimers>
// call <ff8_en.UpdateTimers>
// call <ff8_en.UpdateTimers>
// call <ff8_en.UpdateTimers>
// cmp word ptr ds:[<battle_phase>],3
// jne ff8_en.47D0BB
// push ebx
// call <ff8_en.sub_4A76E0>
// add esp,4
// call <ff8_en.sub_4A8E30>
// call <ff8_en.sub_4A84E0>
// call <ff8_en.sub_4A8E30>
// call <ff8_en.sub_4A84E0>
// call <ff8_en.sub_4A8E30>
// call <ff8_en.sub_4A84E0>
// call <ff8_en.IsWindowActive>
// test eax,eax
// je ff8_en.47D10A
// push esi
// call <ff8_en.sub_41E99D>
// add esp,4
// pop esi
// pop ebx
// add esp,1C
// ret 
// mov byte ptr ds:[1D28DE9],bl
// mov eax,dword ptr ds:[1CFF834]
// cmp eax,ebx
// je ff8_en.47D0E7
// call <ff8_en.sub_5003A0>
// mov eax,dword ptr ds:[1CFF844]
// mov dword ptr ds:[1CFF834],ebx
// cmp eax,ebx
// je ff8_en.47D067
// mov dword ptr ds:[esi+B88],ebx
// call <ff8_en.___setargv_0>
// jmp ff8_en.47D076
// mov al,byte ptr ds:[1D28DE9]
// cmp al,bl
// jne ff8_en.47D118
// call <ff8_en.FFBattleDirector?>
// cmp word ptr ds:[<battle_phase>],3
// jne ff8_en.47D150
// xor eax,eax
// mov al,byte ptr ds:[1D96A80]
// lea ecx,dword ptr ds:[eax+eax*2]
// shl ecx,3
// sub ecx,eax
// lea edx,dword ptr ds:[ecx*4+1D969C8]
// push edx
// call <ff8_en.sub_4A76E0>
// add esp,4
// call <ff8_en.sub_4A8E30>
// call <ff8_en.sub_4A84E0>
// call <ff8_en.sub_4A78E0>
// cmp dword ptr ds:[<StopBattleDword>],ebx
// je ff8_en.47D1AA
// cmp word ptr ds:[<battle_phase>],4
// jne ff8_en.47D17C
// mov dword ptr ss:[esp+10],<ff8_en.FFMenuInitSystem>
// mov dword ptr ss:[esp+14],<ff8_en.FFMenuExitSystem>
// mov dword ptr ss:[esp+18],<ff8_en.FFBattleEndMenu>
// jmp ff8_en.47D194
// mov dword ptr ss:[esp+10],<ff8_en.FFModuleHandlerInitSystem>
// mov dword ptr ss:[esp+14],<ff8_en.FFModuleHandlerExitSystem>
// mov dword ptr ss:[esp+18],<ff8_en.FFModuleHandler>
// lea eax,dword ptr ss:[esp+8]
// push esi
// push eax
// mov dword ptr ss:[esp+24],ebx
// mov dword ptr ss:[esp+28],ebx
// call <ff8_en.FFSwitchModule>
// add esp,8
// mov al,byte ptr ds:[1D28DE9]
// cmp al,bl
// jne ff8_en.47D1FA
// mov eax,dword ptr ds:[1CFF6F4]
// cmp eax,ebx
// je ff8_en.47D1F3
// mov edx,dword ptr ds:[<height>]
// xor ecx,ecx
// cmp eax,2
// mov eax,dword ptr ds:[<width>]
// sete cl
// push ecx
// mov ecx,dword ptr ds:[1A77648]
// push 3AC49BA6
// push edx
// mov edx,dword ptr ds:[1A7764C]
// push eax
// push ecx
// push edx
// call <ff8_en.sub_56D1D0>
// add esp,18
// mov dword ptr ds:[1CFF6F4],ebx
// call <ff8_en.nullsub_32>
// jmp ff8_en.47D204
// push FFFFFFFF
// call <ff8_en.sub_45D610>
// add esp,4
// cmp dword ptr ds:[1CFF834],ebx
// je ff8_en.47D213
// mov byte ptr ds:[1D28DE9],1
// cmp dword ptr ds:[1CFF844],ebx
// jne ff8_en.47D235
// call <ff8_en.sub_4980C0>
// call <ff8_en.sub_465930>
// push esi
// push 1
// call <ff8_en.sub_41E947>
// add esp,8
// call <ff8_en.sub_499EA0>
// call <ff8_en.sub_45B450>
// push esi
// call <ff8_en.sub_41E99D>
// add esp,4
// call <ff8_en.sub_56D9C0>
// mov eax,dword ptr ds:[B6D970]
// cmp eax,ebx
// je ff8_en.47D265
// cmp dword ptr ds:[1CFF834],ebx
// jne ff8_en.47D265
// call <ff8_en.UpdateRateRelated>
// mov dword ptr ds:[1CFF844],eax
// jmp ff8_en.47D26B
// mov dword ptr ds:[1CFF844],ebx
// fld qword ptr ds:[1A78BE0]
// call <ff8_en.__ftol>
// push eax
// call <ff8_en.sub_46BD10>
// add esp,4
// pop esi
// pop ebx
// add esp,1C
// ret 