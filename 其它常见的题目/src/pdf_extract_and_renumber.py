import PyPDF2
from reportlab.pdfgen import canvas
from reportlab.lib.pagesizes import letter
from io import BytesIO

# 函数用于创建具有新页码的页面
def create_watermarked_page(original_page, new_page_number):
    packet = BytesIO()
    can = canvas.Canvas(packet, pagesize=letter)
    can.setFont("Helvetica", 12)
    # 在页面底部中心位置添加页码
    can.drawString(300, 20, str(new_page_number))
    can.save()

    packet.seek(0)
    new_pdf = PyPDF2.PdfReader(packet)
    page = original_page

    page.merge_page(new_pdf.pages[0])
    return page

# 打开原始 PDF 文件
with open('/Users/wxquare/Desktop/EW03366.pdf', 'rb') as input_pdf:
    reader = PyPDF2.PdfReader(input_pdf)
    
    # 创建一个新的 PDF 文件
    writer = PyPDF2.PdfWriter()
    
    # 检查是否有至少18页
    if len(reader.pages) >= 18:
        # 获取第17页和第18页（注意：索引从0开始）
        pages_to_extract = [16, 17]
        
        # 将第17页和第18页添加到新的 PDF 中，并修改页码为1和2
        for i, page_number in enumerate(pages_to_extract, start=1):
            original_page = reader.pages[page_number]
            watermarked_page = create_watermarked_page(original_page, i)
            writer.add_page(watermarked_page)
        
        # 保存新的 PDF 文件
        with open('output.pdf', 'wb') as output_pdf:
            writer.write(output_pdf)
    else:
        print("输入的 PDF 文件少于18页。")
