# 學生成績管理系統

這是 C++ Template 延伸自主練習作業的「第 2 週整合應用小專題」。
本專案使用 C++ 標準模板函式庫 (STL) 中的 `std::vector` 來管理學生資料，並實作了 C++ Template Function 來計算成績統計，為基礎資料結構的應用練習。

##  系統功能

本系統提供命令列介面 (CLI)，包含以下核心功能：
1. **Add student (新增學生)**：輸入學號、姓名與成績。具備學號防呆機制，避免重複新增。
2. **List all students (列出所有學生)**：以格式化的表格輸出目前所有的學生資料。
3. **Sort by score (依成績排序)**：利用 `<algorithm>` 的 `std::sort` 將全班成績由高至低進行排序。
4. **Search by id (查詢學生)**：輸入特定學號，快速尋找並顯示該學生資料。
5. **Show statistics (統計成績)**：顯示全班平均、及格/不及格人數，並利用自訂的 Template Function (`getMax`, `getMin`) 計算最高分與最低分。

##  檔案結構

* `main.cpp`：系統主程式原始碼，包含所有功能邏輯與防呆機制。
* `README.md`：專案說明文件。
* `report.pdf` (或 `report.md`)：自主學習報告，包含設計說明與學習反思。
