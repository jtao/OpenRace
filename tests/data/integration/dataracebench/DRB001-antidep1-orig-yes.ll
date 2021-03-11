; ModuleID = '../micro-benchmarks/DRB001-antidep1-orig-yes.c'
source_filename = "../micro-benchmarks/DRB001-antidep1-orig-yes.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@.str = private unnamed_addr constant [11 x i8] c"a[500]=%d\0A\00", align 1

; Function Attrs: noinline norecurse optnone sspstrong uwtable
define dso_local i32 @main(i32 %argc, i8** %argv) #0 !dbg !9 {
entry:
  %retval = alloca i32, align 4
  %argc.addr = alloca i32, align 4
  %argv.addr = alloca i8**, align 8
  %i = alloca i32, align 4
  %len = alloca i32, align 4
  %a = alloca [1000 x i32], align 16
  store i32 0, i32* %retval, align 4
  store i32 %argc, i32* %argc.addr, align 4
  call void @llvm.dbg.declare(metadata i32* %argc.addr, metadata !16, metadata !DIExpression()), !dbg !17
  store i8** %argv, i8*** %argv.addr, align 8
  call void @llvm.dbg.declare(metadata i8*** %argv.addr, metadata !18, metadata !DIExpression()), !dbg !19
  call void @llvm.dbg.declare(metadata i32* %i, metadata !20, metadata !DIExpression()), !dbg !21
  call void @llvm.dbg.declare(metadata i32* %len, metadata !22, metadata !DIExpression()), !dbg !23
  store i32 1000, i32* %len, align 4, !dbg !23
  call void @llvm.dbg.declare(metadata [1000 x i32]* %a, metadata !24, metadata !DIExpression()), !dbg !28
  store i32 0, i32* %i, align 4, !dbg !29
  br label %for.cond, !dbg !31

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, i32* %i, align 4, !dbg !32
  %1 = load i32, i32* %len, align 4, !dbg !34
  %cmp = icmp slt i32 %0, %1, !dbg !35
  br i1 %cmp, label %for.body, label %for.end, !dbg !36

for.body:                                         ; preds = %for.cond
  %2 = load i32, i32* %i, align 4, !dbg !37
  %3 = load i32, i32* %i, align 4, !dbg !38
  %idxprom = sext i32 %3 to i64, !dbg !39
  %arrayidx = getelementptr inbounds [1000 x i32], [1000 x i32]* %a, i64 0, i64 %idxprom, !dbg !39
  store i32 %2, i32* %arrayidx, align 4, !dbg !40
  br label %for.inc, !dbg !39

for.inc:                                          ; preds = %for.body
  %4 = load i32, i32* %i, align 4, !dbg !41
  %inc = add nsw i32 %4, 1, !dbg !41
  store i32 %inc, i32* %i, align 4, !dbg !41
  br label %for.cond, !dbg !42, !llvm.loop !43

for.end:                                          ; preds = %for.cond
  store i32 0, i32* %i, align 4, !dbg !45
  br label %for.cond1, !dbg !47

for.cond1:                                        ; preds = %for.inc9, %for.end
  %5 = load i32, i32* %i, align 4, !dbg !48
  %6 = load i32, i32* %len, align 4, !dbg !50
  %sub = sub nsw i32 %6, 1, !dbg !51
  %cmp2 = icmp slt i32 %5, %sub, !dbg !52
  br i1 %cmp2, label %for.body3, label %for.end11, !dbg !53

for.body3:                                        ; preds = %for.cond1
  %7 = load i32, i32* %i, align 4, !dbg !54
  %add = add nsw i32 %7, 1, !dbg !55
  %idxprom4 = sext i32 %add to i64, !dbg !56
  %arrayidx5 = getelementptr inbounds [1000 x i32], [1000 x i32]* %a, i64 0, i64 %idxprom4, !dbg !56
  %8 = load i32, i32* %arrayidx5, align 4, !dbg !56
  %add6 = add nsw i32 %8, 1, !dbg !57
  %9 = load i32, i32* %i, align 4, !dbg !58
  %idxprom7 = sext i32 %9 to i64, !dbg !59
  %arrayidx8 = getelementptr inbounds [1000 x i32], [1000 x i32]* %a, i64 0, i64 %idxprom7, !dbg !59
  store i32 %add6, i32* %arrayidx8, align 4, !dbg !60
  br label %for.inc9, !dbg !59

for.inc9:                                         ; preds = %for.body3
  %10 = load i32, i32* %i, align 4, !dbg !61
  %inc10 = add nsw i32 %10, 1, !dbg !61
  store i32 %inc10, i32* %i, align 4, !dbg !61
  br label %for.cond1, !dbg !62, !llvm.loop !63

for.end11:                                        ; preds = %for.cond1
  %arrayidx12 = getelementptr inbounds [1000 x i32], [1000 x i32]* %a, i64 0, i64 500, !dbg !65
  %11 = load i32, i32* %arrayidx12, align 16, !dbg !65
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str, i64 0, i64 0), i32 %11), !dbg !66
  ret i32 0, !dbg !67
}

; Function Attrs: nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare i32 @printf(i8*, ...) #2

attributes #0 = { noinline norecurse optnone sspstrong uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone speculatable willreturn }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4, !5, !6, !7}
!llvm.ident = !{!8}

!0 = distinct !DICompileUnit(language: DW_LANG_C_plus_plus_14, file: !1, producer: "clang version 11.1.0", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "../micro-benchmarks/DRB001-antidep1-orig-yes.c", directory: "/home/brad/Code/GitLabOpenRace/external/dataracebench/micro-benchmarks")
!2 = !{}
!3 = !{i32 7, !"Dwarf Version", i32 4}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 4}
!6 = !{i32 7, !"PIC Level", i32 2}
!7 = !{i32 7, !"PIE Level", i32 2}
!8 = !{!"clang version 11.1.0"}
!9 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 52, type: !10, scopeLine: 53, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!10 = !DISubroutineType(types: !11)
!11 = !{!12, !12, !13}
!12 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!13 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !14, size: 64)
!14 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !15, size: 64)
!15 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!16 = !DILocalVariable(name: "argc", arg: 1, scope: !9, file: !1, line: 52, type: !12)
!17 = !DILocation(line: 52, column: 14, scope: !9)
!18 = !DILocalVariable(name: "argv", arg: 2, scope: !9, file: !1, line: 52, type: !13)
!19 = !DILocation(line: 52, column: 26, scope: !9)
!20 = !DILocalVariable(name: "i", scope: !9, file: !1, line: 54, type: !12)
!21 = !DILocation(line: 54, column: 7, scope: !9)
!22 = !DILocalVariable(name: "len", scope: !9, file: !1, line: 55, type: !12)
!23 = !DILocation(line: 55, column: 7, scope: !9)
!24 = !DILocalVariable(name: "a", scope: !9, file: !1, line: 57, type: !25)
!25 = !DICompositeType(tag: DW_TAG_array_type, baseType: !12, size: 32000, elements: !26)
!26 = !{!27}
!27 = !DISubrange(count: 1000)
!28 = !DILocation(line: 57, column: 7, scope: !9)
!29 = !DILocation(line: 59, column: 9, scope: !30)
!30 = distinct !DILexicalBlock(scope: !9, file: !1, line: 59, column: 3)
!31 = !DILocation(line: 59, column: 8, scope: !30)
!32 = !DILocation(line: 59, column: 13, scope: !33)
!33 = distinct !DILexicalBlock(scope: !30, file: !1, line: 59, column: 3)
!34 = !DILocation(line: 59, column: 15, scope: !33)
!35 = !DILocation(line: 59, column: 14, scope: !33)
!36 = !DILocation(line: 59, column: 3, scope: !30)
!37 = !DILocation(line: 60, column: 11, scope: !33)
!38 = !DILocation(line: 60, column: 7, scope: !33)
!39 = !DILocation(line: 60, column: 5, scope: !33)
!40 = !DILocation(line: 60, column: 9, scope: !33)
!41 = !DILocation(line: 59, column: 21, scope: !33)
!42 = !DILocation(line: 59, column: 3, scope: !33)
!43 = distinct !{!43, !36, !44}
!44 = !DILocation(line: 60, column: 11, scope: !30)
!45 = !DILocation(line: 63, column: 9, scope: !46)
!46 = distinct !DILexicalBlock(scope: !9, file: !1, line: 63, column: 3)
!47 = !DILocation(line: 63, column: 8, scope: !46)
!48 = !DILocation(line: 63, column: 12, scope: !49)
!49 = distinct !DILexicalBlock(scope: !46, file: !1, line: 63, column: 3)
!50 = !DILocation(line: 63, column: 15, scope: !49)
!51 = !DILocation(line: 63, column: 19, scope: !49)
!52 = !DILocation(line: 63, column: 13, scope: !49)
!53 = !DILocation(line: 63, column: 3, scope: !46)
!54 = !DILocation(line: 64, column: 12, scope: !49)
!55 = !DILocation(line: 64, column: 13, scope: !49)
!56 = !DILocation(line: 64, column: 10, scope: !49)
!57 = !DILocation(line: 64, column: 16, scope: !49)
!58 = !DILocation(line: 64, column: 7, scope: !49)
!59 = !DILocation(line: 64, column: 5, scope: !49)
!60 = !DILocation(line: 64, column: 9, scope: !49)
!61 = !DILocation(line: 63, column: 24, scope: !49)
!62 = !DILocation(line: 63, column: 3, scope: !49)
!63 = distinct !{!63, !53, !64}
!64 = !DILocation(line: 64, column: 17, scope: !46)
!65 = !DILocation(line: 66, column: 26, scope: !9)
!66 = !DILocation(line: 66, column: 3, scope: !9)
!67 = !DILocation(line: 67, column: 3, scope: !9)
